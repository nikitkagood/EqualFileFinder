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

    std::vector<std::filesystem::path> folder1_files = getFilePaths(folder1);
    std::vector<std::filesystem::path> folder2_files = getFilePaths(folder2);

    for(const auto& f1 : folder1_files)
    {
        std::vector<std::string> temp {f1.string()};

        for(const auto& f2 : folder2_files)
        {
            if(isEqualFiles(f1, f2) == true)
            {
                temp.push_back(f2.string());
            }
        }

        if(temp.size() > 1) //some files are equal
        {
            search_results.push_back(temp);
        }
    }

}

bool EqualFileFinder::isEqualFiles(const std::filesystem::path& left_file_path, const std::filesystem::path& right_file_path)
{
    if(settings.at(Settings::TheSameFileNames) == true)
    {
        if(left_file_path.filename() != right_file_path.filename())
        {
            return false;
        }
    }

    lFileStream.open(left_file_path, std::ifstream::in | std::ifstream::binary);
    rFileStream.open(right_file_path, std::ifstream::in | std::ifstream::binary);

    if(!lFileStream.is_open() || !rFileStream.is_open())
    {
        return false;
    }

    bool is_equal = true;

    while (lFileStream.good() || rFileStream.good())
    {
        lFileStream.read(lBuffer.data(), BUFFER_SIZE);
        rFileStream.read(rBuffer.data(), BUFFER_SIZE);

        if(lBuffer != rBuffer)
        {
            is_equal = false;
            break;
        }
    }

    //clear everything
    std::fill(std::begin(lBuffer), std::end(lBuffer), 0);
    std::fill(std::begin(rBuffer), std::end(rBuffer), 0);
    lFileStream.clear();
    rFileStream.clear();
    lFileStream.close();
    rFileStream.close();

    return is_equal;
}

std::vector<std::filesystem::path> EqualFileFinder::getFilePaths(const std::string& folder) const
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
        std::vector<std::filesystem::path> result;

        for(const auto& file : directory_iterator)
        {
            if(predicate(file))
            {
                result.push_back(file.path());
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
