#ifndef SOURCE_GROUP_SETTINGS_WITH_INDEXED_HEADER_PATHS_H
#define SOURCE_GROUP_SETTINGS_WITH_INDEXED_HEADER_PATHS_H

#include <memory>
#include <string>
#include <vector>

#include "SourceGroupSettingsBase.h"

class ConfigManager;
class FilePath;

class SourceGroupSettingsWithIndexedHeaderPaths
	: virtual public SourceGroupSettingsBase
{
public:
	SourceGroupSettingsWithIndexedHeaderPaths();
	virtual ~SourceGroupSettingsWithIndexedHeaderPaths() = default;

	bool equals(std::shared_ptr<SourceGroupSettingsWithIndexedHeaderPaths> other) const;

	std::vector<FilePath> getIndexedHeaderPaths() const;
	std::vector<FilePath> getIndexedHeaderPathsExpandedAndAbsolute() const;
	void setIndexedHeaderPaths(const std::vector<FilePath>& indexedHeaderPaths);

protected:
	void load(std::shared_ptr<const ConfigManager> config, const std::string& key);
	void save(std::shared_ptr<ConfigManager> config, const std::string& key);

private:
	std::vector<FilePath> m_indexedHeaderPaths;
};

#endif // SOURCE_GROUP_SETTINGS_WITH_INDEXED_HEADER_PATHS_H