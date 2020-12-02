#include "RenderSettings.h"
#include <fstream>
#include "nlohmann/json.hpp"

FRenderSettings& FRenderSettings::Get()
{
    static FRenderSettings RenderSettings;
    return RenderSettings;
}

void FRenderSettings::SaveSettings(const std::string& Path)
{
    std::ofstream FileWriter;

    FileWriter.open(Path);
    if (FileWriter.is_open())
    {
        nlohmann::json Json;
        Json[GET_MEMBER_NAME_CHECKED(FRenderSettings, DisplaySize)] = DisplaySize.GetName();

        FileWriter << Json;
    }
    FileWriter.close();
}

void FRenderSettings::LoadSettings(const std::string& Path)
{
    std::ifstream FileReader;

    FileReader.open(Path);
    if (FileReader.is_open())
    {
        nlohmann::json Json;
        FileReader >> Json;

        if (Json[GET_MEMBER_NAME_CHECKED(FRenderSettings, DisplaySize)].is_string())
        {
            DisplaySize = FDisplaySize::GetDisplaySizeByName(Json[GET_MEMBER_NAME_CHECKED(FRenderSettings, DisplaySize)]);
        }
    }
    FileReader.close();
}

FRenderSettings::FRenderSettings()
{

}
