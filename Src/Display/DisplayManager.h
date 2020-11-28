#pragma once

class MDisplayManager
{
public:
    static MDisplayManager& Get();

    void CreateDisplay();

private:
    MDisplayManager();
};