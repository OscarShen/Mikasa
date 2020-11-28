#include "RenderSettings.h"

MRenderSettings& MRenderSettings::Get()
{
    static MRenderSettings RenderSettings;
    return RenderSettings;
}

void MRenderSettings::SaveSettings(const MString& Path)
{
    MFileWriter FileWriter;

    FileWriter.open(Path);
    if (FileWriter.is_open())
    {
        MJson Json;
        Json[GET_MEMBER_NAME_CHECKED(MRenderSettings, DisplaySize)] = DisplaySize.GetName();

        FileWriter << Json;
    }
    FileWriter.close();
}

void MRenderSettings::LoadSettings(const MString& Path)
{
    MFileReader FileReader;

    FileReader.open(Path);
    if (FileReader.is_open())
    {
        MJson Json;
        FileReader >> Json;

        if (Json[GET_MEMBER_NAME_CHECKED(MRenderSettings, DisplaySize)].is_string())
        {
            DisplaySize = MDisplaySize::GetDisplaySizeByName(Json[GET_MEMBER_NAME_CHECKED(MRenderSettings, DisplaySize)]);
        }
    }
    FileReader.close();
}

MRenderSettings::MRenderSettings()
{

}
