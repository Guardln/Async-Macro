#include <iostream>
#include <fstream>
#include <xmemory>
#include <istream>
#include <algorithm>
#include <string>
#include "../globals.hh"
#include "../H/skStr.h"

//using namespace std;

void macro::load()
{
    std::string loc = "c:/configs/";
    std::string cfg = settings.config;
    std::string typ = ".cfg";

    std::ifstream cFile(loc + cfg + typ);
    if (cFile.is_open())
    {
        std::string line;
        while (std::getline(cFile, line))
        {
            line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
            if (line[0] == '#' || line.empty()) continue;

            auto delimiterPos = line.find(xorstr("="));
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);

            if (name == xorstr("primarySmooth")) settings.sleep1 = stoi(value);
            if (name == xorstr("secondarySmooth")) settings.sleep2 = stoi(value);
            if (name == xorstr("secondaryX")) settings.secondary.x = stof(value);
            if (name == xorstr("secondaryY")) settings.secondary.y = stof(value);
            if (name == xorstr("primaryX")) settings.primary.x = stof(value);
            if (name == xorstr("primaryY")) settings.primary.y = stof(value);
            
        }
    }
}

void macro::save()
{
    std::string loc = "c:/configs/";
    std::string cfg = settings.config;
    std::string typ = ".cfg";

    std::fstream f;

    f.open(loc + cfg + typ, std::ios_base::out | std::ios_base::trunc);

    if (f.is_open())
    {
        f << xorstr("primarySmooth = ") << settings.sleep1 << std::endl;
        f << xorstr("secondarySmooth = ") << settings.sleep2 << std::endl;
        f << xorstr("secondaryX = ") << settings.secondary.x << std::endl;
        f << xorstr("secondaryY = ") << settings.secondary.y << std::endl;
        f << xorstr("primaryX = ") << settings.primary.x << std::endl;
        f << xorstr("primaryY = ") << settings.primary.y << std::endl;


        f.close();
    }
}