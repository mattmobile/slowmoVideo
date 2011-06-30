/*
slowmoVideo creates slow-motion videos from normal-speed videos.
Copyright (C) 2011  Simon A. Eugster (Granjow)  <simon.eu@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
*/

#ifndef FLOWRW_SV_H
#define FLOWRW_SV_H

#include <string>

class FlowField_sV;

/**
  \brief Reads and writes Optical Flow fields.
  \see FlowField_sV
  \todo Cast exception if the file is not a valid flow file
  */
class FlowRW_sV
{
public:

    struct FlowInfo_sV {
        int width;
        int height;
        char version;
        std::string magic;
        bool valid;
        FlowInfo_sV() {
            magic = "flow_sV";
            version = '1';
            valid = false;
        }
    };

    /** \fn load(std::string)
      \return \tt NULL, if the file could not be loaded, and the flow field otherwise.
      */
    /** \fn save(std::string, FlowField_sV*);
      \see FlowField_sV::FlowField_sV(int, int, float*, FlowField_sV::GLFormat)
      */
    /** \fn readInfo(std::string)
      \return Information about the flow file (like dimension); Does not read the whole file and is therefore faster than load(std::string).
      */
    static void save(std::string filename, FlowField_sV *flowField);
    static FlowField_sV* load(std::string filename);

    static FlowInfo_sV readInfo(std::string filename);

private:
    static const std::string m_magicNumber;
    static const char m_version;
};

#endif // FLOWRW_SV_H