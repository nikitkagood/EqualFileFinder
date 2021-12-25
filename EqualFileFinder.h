#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <filesystem>
#include <stdexcept>
#include <functional>
#include <iterator>

#include <QCryptographicHash>
#include <QByteArray>
#include <QString>

#include "Profiler.h"

class EqualFileFinder
{
public:
    EqualFileFinder() = default;

    EqualFileFinder(const EqualFileFinder& copy) = delete;

    ~EqualFileFinder() = default;

    enum class Settings
    {
        TheSameFileNames,
        FolderRecursion,
        ExcludeEmptyFiles,
    };

    void findEqualFiles(const std::string& folder1, const std::string& folder2);

    const std::vector<std::vector<std::string>>& getSearchResults() const
    {
        return search_results;
    }

    void changeSetting(EqualFileFinder::Settings setting, bool value)
    {
        settings.at(setting) = value;
    }

private:
    static const unsigned int BUFFER_SIZE = 1024 * 5; //in bytes

    void findEqualHashes();

    std::vector<std::filesystem::directory_entry> getFilePaths(const std::string& folder) const;

    std::map<std::filesystem::directory_entry, QByteArray> calcHashes(std::vector<std::filesystem::directory_entry> directories);

    std::ifstream fileStream;
    std::array<char, BUFFER_SIZE> dataBuffer;
    std::vector<std::vector<std::string>> search_results;

    std::map<Settings, bool> settings //it already contains default settings
    {
        {Settings::TheSameFileNames, false},
        {Settings::FolderRecursion, false},
        {Settings::ExcludeEmptyFiles, true}
    };

    QCryptographicHash hash_algorithm{ QCryptographicHash::Algorithm::Md5 };
    std::map<std::filesystem::directory_entry, QByteArray> lHashes;
    std::map<std::filesystem::directory_entry, QByteArray> rHashes;
};
