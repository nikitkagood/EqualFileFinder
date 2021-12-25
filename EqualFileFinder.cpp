#include "EqualFileFinder.h"

void EqualFileFinder::findEqualFiles(const std::string& folder1, const std::string& folder2)
{
    LOG_DURATION(__FUNCTION__)

    if(folder1.empty())
    {
        throw std::string{"Folder 1 is not selected"};
        return;
    }
    if(folder2.empty())
    {
        throw std::string{"Folder 2 is not selected"};
        return;
    }

    if(folder1 == folder2)
    {
        throw std::string{"Folders are the same"};
        return;
    }

    if(!std::filesystem::exists(folder1))
    {
        throw std::runtime_error("Path " + folder1 + " does not exist");
        return;
    }
    if(!std::filesystem::exists(folder2))
    {
        throw std::runtime_error("Path " + folder2 + " does not exist");
        return;
    }

    auto folder1_files = getFilePaths(folder1);
    auto folder2_files = getFilePaths(folder2);

    lHashes = std::move(calcHashes(folder1_files));
    rHashes = std::move(calcHashes(folder2_files));

    findEqualHashes();

}

void EqualFileFinder::findEqualHashes()
{
    for(const auto& lHash : lHashes)
    {
        std::vector<std::string> temp{ lHash.first.path().string() };

        for(const auto& rHash : rHashes)
        {
            bool is_equal = true;
            for(size_t i = 0; i < lHash.second.size(); i++)
            {
                if(lHash.second[i] != rHash.second[i])
                {
                    is_equal = false;
                    break;
                }
            }

            if(is_equal)
            {
                temp.push_back(rHash.first.path().string());
            }
        }

        if(temp.size() > 1) //some files are equal
        {
            search_results.push_back(temp);
        }
    }

}

std::vector<std::filesystem::directory_entry> EqualFileFinder::getFilePaths(const std::string& folder) const
{
    std::function<bool(std::filesystem::directory_entry)> file_predicate = [&](const auto&)
    {
        //default - no predicate
        return true;
    };

    if(settings.at(Settings::ExcludeEmptyFiles) == true)
    {
        file_predicate = [&](const auto& file)
        {
            if(file.file_size() != 0)
            {
                return true;

            }
            else return false;
        };
    }

    auto get_entries = [&](auto&& directory_iterator, const auto& predicate)
    {
        std::vector<std::filesystem::directory_entry> result;

        for(const auto& file : directory_iterator)
        {
            if(predicate(file))
            {
                result.push_back(file);
            }
        }

        return result;
    };

    if(settings.at(Settings::FolderRecursion) == true)
    {
        return get_entries(std::filesystem::recursive_directory_iterator(folder), file_predicate);
    }
    else
    {
        return get_entries(std::filesystem::directory_iterator(folder), file_predicate);
    }
}

std::map<std::filesystem::directory_entry, QByteArray> EqualFileFinder::calcHashes(std::vector<std::filesystem::directory_entry> directories)
{
    std::map<std::filesystem::directory_entry, QByteArray> hashes;

    for(const auto& dir_entry : directories)
    {
        if(dir_entry.file_size() == 0)
        {
            hashes.insert({ dir_entry, QByteArray() });
            continue;
        }

        fileStream.open(dir_entry, std::ifstream::in | std::ifstream::binary);

        if(!fileStream.is_open())
        {
            throw std::runtime_error("File stream failed to open - cannot read a file");
        }

        unsigned left_to_read = dir_entry.file_size();

        while (fileStream.good())
        {
            if(left_to_read >= BUFFER_SIZE)
            {
                fileStream.read(dataBuffer.data(), BUFFER_SIZE);
                hash_algorithm.addData(dataBuffer.data(), dataBuffer.size());
                left_to_read -= BUFFER_SIZE;

                std::fill(std::begin(dataBuffer), std::end(dataBuffer), 0);
            }
            else
            {
                fileStream.read(dataBuffer.data(), left_to_read);
                hash_algorithm.addData(dataBuffer.data(), left_to_read);

                std::fill(std::begin(dataBuffer), std::begin(dataBuffer) + left_to_read, 0);
            }
        }

        hashes.insert({ dir_entry, hash_algorithm.result().toHex() });
        hash_algorithm.reset();

        fileStream.clear();
        fileStream.close();
    }

    return hashes;
}

