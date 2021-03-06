#pragma once

//#include "private/seniverse-apikey.h"
#include "private/openweather-apikey.h"
#include "common/weathercn_api.h"

namespace weather
{

typedef std::function<std::string(::int64_t, ::int64_t, std::vector<std::string>&, const char*)> callback;
enum class commands : size_t {
    全球天气,
    国内天气
};
inline std::map<std::string, commands> commands_regex
{
    {R"(^weather +(?<city>.+) *$)", commands::全球天气},
    {R"(^ *(?<city>.+) +weather$)", commands::全球天气},
    {R"(^ *(?<city>.+)(天气|天氣)$)", commands::国内天气},
};
struct command
{
    commands c = (commands)0;
    std::vector<std::string> args;
    callback func = nullptr;
};
command msgDispatcher(const json& body);
command weather_global(const std::string& city);
command weather_cn(const std::string& city);


}