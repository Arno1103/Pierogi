//
// lg.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "lg.h"
#include "protocols/necprotocol.h"
#include "protocols/necxprotocol.h"
#include "protocols/rc5protocol.h"
#include <QComboBox>

LGTV1::LGTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      LG_Make,
      TV_Panels,
      index)
{
  addControlledDevice(LG_Make, "32LC56", TV_Device);
  addControlledDevice(LG_Make, "32LH301C", TV_Device);
  addControlledDevice(LG_Make, "50PS3000", TV_Device);
  addControlledDevice(LG_Make, "FLATRON M227WDP", TV_Device);
  addControlledDevice(LG_Make, "FLATRON M2280DF", TV_Device);
}


void LGTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);
  threadableProtocol->setMinimumRepetitions(1);

  setPreData(0x04, 8);

  addKey("p+", ChannelUp_Key, 0x00, 8);
  addKey("p-", ChannelDown_Key, 0x01, 8);
  addKey("vol+", VolumeUp_Key, 0x02, 8);
  addKey("vol-", VolumeDown_Key, 0x03, 8);
  addKey("right", Right_Key, 0x06, 8);
  addKey("left", Left_Key, 0x07, 8);
  addKey("power", Power_Key, 0x08, 8);
  addKey("mute", Mute_Key, 0x09, 8);
  addKey("sap", Audio_Key, 0x0A, 8); // "I/II", "tv/av"
  addKey("input", Input_Key, 0x0B, 8);
  addKey("picture", PictureMode_Key, 0x0C, 8);
  addKey("sound", SoundMode_Key, 0x0D, 8);
  addKey("sleep", Sleep_Key, 0x0E, 8);
  addKey("TvVideo", OpticalInput_Key, 0x0F, 8);  // Hack
  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("qview", PrevChannel_Key, 0x1A, 8); // "review", "ChannelPrev"
  addKey("fav", Favorites_Key, 0x1E, 8);
  addKey("text", Teletext_Key, 0x20, 8);
  addKey("topt", Unmapped_Key, 0x21, 8); // "topt/rev", "t.opt"
  addKey("MIX", TeletextAndTV_Key, 0x24, 8);
  addKey("TIME", TeletextTime_Key, 0x26, 8);
  addKey("INDEX", TeletextIndex_Key, 0x27, 8);
  addKey("return/exit", Exit_Key, 0x28, 8);
  addKey("reveal", TeletextReveal_Key, 0x2A, 8);
  addKey("avmode", Unmapped_Key, 0x30, 8); // "UPDATE"
  addKey("subtitle", Captions_Key, 0x39, 8); // "cc", "subtitle/ffw"
  addKey("up", Up_Key, 0x40, 8);
  addKey("down", Down_Key, 0x41, 8);
  addKey("menu", Menu_Key, 0x43, 8); // "setup menu", "Home"
  addKey("ok", Select_Key, 0x44, 8);
  addKey("qmenu", Unmapped_Key, 0x45, 8);
  addKey("-", Dash_Key, 0x4C, 8);
  addKey("video", PictureMode_Key, 0x4D, 8); // "apc", "PSM", "picture mode"
  addKey("TV/PC", LDInput_Key, 0x50, 8); // This is a hack
  addKey("AV-2", Composite2Input_Key, 0x51, 8);
  addKey("sound", SoundMode_Key, 0x52, 8); // "SSM", "Select Sound Mode"
  addKey("list", Unmapped_Key, 0x53, 8);
  addKey("auto", Unmapped_Key, 0x54, 8);
  addKey("memory/erase", Memory_Key, 0x55, 8);
  addKey("av1", CompositeInput_Key, 0x5A, 8);
  addKey("pip", PIP_Key, 0x60, 8);
  addKey("blue", Blue_Key, 0x61, 8);
  addKey("blue/pause", Pause_Key, 0x61, 8);
  addKey("yellow", Yellow_Key, 0x63, 8);
  addKey("yellow/play", Play_Key, 0x63, 8);
  addKey("brt.w", Unmapped_Key, 0x6E, 8);
  addKey("green", Green_Key, 0x71, 8);
  addKey("green/stop", Stop_Key, 0x71, 8);
  addKey("red", Red_Key, 0x72, 8);
  addKey("ratio", AspectRatio_Key, 0x79, 8);
  addKey("xstudio", Unmapped_Key, 0x7C, 8);
  addKey("simplink", Unmapped_Key, 0x7E, 8);
  addKey("Ratio16:9", Unmapped_Key, 0x88, 8);
  addKey("Ratio4:3", Unmapped_Key, 0x89, 8);
  addKey("app/x", Unmapped_Key, 0x90, 8);
  addKey("ad", Unmapped_Key, 0x91, 8);
  addKey("energy", Unmapped_Key, 0x95, 8); // "EYEASTERISK"
  addKey("comp-rgb-dvi", TapeInput_Key, 0x98, 8);  // Hack
  addKey("InputAv1", SVideoInput_Key, 0xA5, 8);
  addKey("info", Info_Key, 0xAA, 8);
  addKey("guide", Guide_Key, 0xAB, 8);
  addKey("RatioZoom", Zoom_Key, 0xAF, 8);
  addKey("rec", Record_Key, 0xBD, 8);
  addKey("InputComponent1", ComponentInput_Key, 0xBF, 8);
  addKey("PowerOn", PowerOn_Key, 0xC4, 8);
  addKey("PowerOff", PowerOff_Key, 0xC5, 8);
  addKey("hdmi", HDMIInput_Key, 0xC6, 8);
  addKey("InputHDMI2", HDMI2Input_Key, 0xCC, 8);
  addKey("InputHDMI1", LineInput_Key, 0xCE, 8); // Hack!
  addKey("InputAv2", SVideo2Input_Key, 0xD0, 8);
  addKey("InputComponent2", Component2Input_Key, 0xD2, 8);
  addKey("InputRgb-Pc", PCInput_Key, 0xD5, 8);
  addKey("aerial", AntennaInput_Key, 0xD6, 8);
  addKey("InputTv", MDInput_Key, 0xD9, 8); // yet another TV input?
  addKey("InputHDMI4", PhonoInput_Key, 0xDA, 8); // too many HDMIs!
  addKey("InputHDMI3", HDMI3Input_Key, 0xE9, 8);
  addKey("Auto Demo Mode", Unmapped_Key, 0xED, 8);
  addKey("tv/radio", TunerInput_Key, 0xF0, 8);

  // Factory controls:
  addKey("Picture Test Mode", Unmapped_Key, 0xF9, 8);
  addKey("InStop(FactoryReset)", FactoryReset_Key, 0xFA, 8);
  addKey("InStart", Unmapped_Key, 0xFB, 8);
  addKey("Password Protected Function", Unmapped_Key, 0xFC, 8);
  addKey("PowerOnly", Unmapped_Key, 0xFE, 8);
  addKey("EZadjust", ServiceMenu_Key, 0xFF, 8);
}


void LGTV1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("TV", QVariant(MDInput_Key));
  cb->addItem("TV / Video", QVariant(OpticalInput_Key));
  cb->addItem("TV / PC", QVariant(LDInput_Key));
  cb->addItem("TV / Radio", QVariant(TunerInput_Key));
  cb->addItem("AV 1", QVariant(CompositeInput_Key));
  cb->addItem("AV 2", QVariant(Composite2Input_Key));
  cb->addItem("AV 1 (alt)", QVariant(SVideoInput_Key));
  cb->addItem("AV 2 (alt)", QVariant(SVideo2Input_Key));
  cb->addItem("Component 1", QVariant(ComponentInput_Key));
  cb->addItem("Component 2", QVariant(Component2Input_Key));
  cb->addItem("HDMI", QVariant(HDMIInput_Key));
  cb->addItem("HDMI 1", QVariant(LineInput_Key));
  cb->addItem("HDMI 2", QVariant(HDMI2Input_Key));
  cb->addItem("HDMI 3", QVariant(HDMI3Input_Key));
  cb->addItem("HDMI 4", QVariant(PhonoInput_Key));
  cb->addItem("Comp / RGB / DVI", QVariant(TapeInput_Key));
  cb->addItem("RGB / PC", QVariant(PCInput_Key));
}


LGTV1a::LGTV1a(
  unsigned int index)
  : LGTV1(index)
{
  setKeysetName("TV Keyset 1a");
}


void LGTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LGTV1::populateProtocol(guiObject);

  addKey("*", Unmapped_Key, 0x39, 8);
  addKey("exit", Exit_Key, 0x5B, 8);
//  addKey("pop", Unmapped_Key, 0x61, 8);
  addKey("pipinput", PIPSource_Key, 0x61, 8);
  addKey("swap", PIPSwap_Key, 0x63, 8);
  addKey("freeze", PIPPause_Key, 0x65, 8);
  addKey("pipch+", PIPChannelUp_Key, 0x71, 8);
  addKey("pipch-", PIPChannelDown_Key, 0x72, 8);
  addKey("zoom", Zoom_Key, 0x7B, 8);
  addKey("signal", Unmapped_Key, 0x96, 8);
  addKey("adjust", Unmapped_Key, 0xCB, 8);
}


LGTV1b::LGTV1b(
  unsigned int index)
  : LGTV1(index)
{
  setKeysetName("TV Keyset 1b");
}


void LGTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LGTV1::populateProtocol(guiObject);

  addKey("PR+/Up_Arrow", Up_Key, 0x00, 8);
  addKey("PR-/Down_Arrow", Down_Key, 0x01, 8);
  addKey("Vol+/Right_Arrow", Right_Key, 0x02, 8);
  addKey("Vol-/Left_Arrow", Left_Key, 0x03, 8);
  addKey("orange", Red_Key, 0xC0, 8);
  addKey("yellow", Yellow_Key, 0xC1, 8);
  addKey("blue", Blue_Key, 0xC2, 8);
  addKey("green", Green_Key, 0xC3, 8);
}


LGTV1c::LGTV1c(
  unsigned int index)
  : LGTV1(index)
{
  setKeysetName("TV Keyset 1c");

  addControlledDevice(LG_Make, "55LW9500", TV_Device);
  addControlledDevice(LG_Make, "60PX950", TV_Device);
  addControlledDevice(LG_Make, "60PG60", TV_Device);
}


void LGTV1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LGTV1::populateProtocol(guiObject);

//  addKey("Mark", Unmapped_Key, 0x1E, 8); // This is probably an error
//  addKey("3DOption", Unmapped_Key, 0x45, 8); // also probably error
//  addKey("List", Unmapped_Key, 0x4C, 8); // also odd
  addKey("info", Info_Key, 0x55, 8);
  addKey("Premium", Unmapped_Key, 0x56, 8);
  addKey("WIDGETS", Unmapped_Key, 0x58, 8);
  addKey("exit", Exit_Key, 0x5B, 8); // "Return"
  addKey("forward", FastForward_Key, 0x8E, 8);
  addKey("backward", Rewind_Key, 0x8F, 8);
  addKey("netcast", Unmapped_Key, 0xA9, 8);
  addKey("play", Play_Key, 0xB0, 8);
  addKey("stop", Stop_Key, 0xB1, 8);
  addKey("pause", Pause_Key, 0xBA, 8); // "Freeze"
  addKey("rec", Record_Key, 0xBD, 8);
  addKey("3D", Unmapped_Key, 0xDC, 8);
}


LGTV2::LGTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      LG_Make,
      TV_Panels,
      index)
{
}


void LGTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index, 0x40);

  addKey("0", Zero_Key, 0x00, 6);
  addKey("1", One_Key, 0x01, 6);
  addKey("2", Two_Key, 0x02, 6);
  addKey("3", Three_Key, 0x03, 6);
  addKey("4", Four_Key, 0x04, 6);
  addKey("5", Five_Key, 0x05, 6);
  addKey("6", Six_Key, 0x06, 6);
  addKey("7", Seven_Key, 0x07, 6);
  addKey("8", Eight_Key, 0x08, 6);
  addKey("9", Nine_Key, 0x09, 6);
  addKey("POWER", Power_Key, 0x0C, 6);
  addKey("MUTE", Mute_Key, 0x0D, 6);
  addKey("PSM", PictureMode_Key, 0x0E, 6); // preset picture
  addKey("LIST", Unmapped_Key, 0x0F, 6);
  addKey("VOLUP", VolumeUp_Key, 0x10, 6);
  addKey("VOLDOWN", VolumeDown_Key, 0x11, 6);
  addKey("EYE", Unmapped_Key, 0x12, 6);
  addKey("TURBOPICTURE", Unmapped_Key, 0x13, 6);
  addKey("DRP", Unmapped_Key, 0x14, 6);
  addKey("KEY_MEDIA", Unmapped_Key, 0x15, 6);
  addKey("SSM", SoundMode_Key, 0x16, 6); // preset sound
  addKey("PROGUP", ChannelUp_Key, 0x20, 6);
  addKey("PROGDOWN", ChannelDown_Key, 0x21, 6);
  addKey("I-II", Audio_Key, 0x23, 6);
  addKey("TURBOSOUND", Unmapped_Key, 0x24, 6);
  addKey("OK", Select_Key, 0x25, 6);
  addKey("STILL", TeletextHold_Key, 0x29, 6); // "KEY_PAUSE", "HOLD"
  addKey("TIME", TeletextTime_Key, 0x2A, 6);
  addKey("SIZE", TeletextSize_Key, 0x2B, 6);  // "KEY_SAVE"
  addKey("REVEAL", TeletextReveal_Key, 0x2C, 6); // "KEY_REDO"
  addKey("POS", PIPMove_Key, 0x2D, 6); // position, "UPDATE"
  addKey("MIX", TeletextAndTV_Key, 0x2E, 6);  // "KEY_MAX"
  addKey("SWAP", PIPSwap_Key, 0x32, 6);
  addKey("ARC", AspectRatio_Key, 0x33, 6);
  addKey("INPUT", Input_Key, 0x34, 6);
  addKey("2-12PIP", Unmapped_Key, 0x35, 6); // strobe, "KEY_SHOP"
  addKey("PR-PLUS", Unmapped_Key, 0x36, 6);
  addKey("PR-MINUS", Unmapped_Key, 0x37, 6);
  addKey("TVAV", Unmapped_Key, 0x38, 6);
  addKey("PIP", PIP_Key, 0x3A, 6);
  addKey("MENU", Menu_Key, 0x3B, 6);
  addKey("TEXT", Teletext_Key, 0x3C, 6);
  addKey("SLEEP", Sleep_Key, 0x3E, 6);
}


LGTV2a::LGTV2a(
  unsigned int index)
  : LGTV2(index)
{
  setKeysetName("TV Keyset 2a");
}


void LGTV2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LGTV2::populateProtocol(guiObject);

  addKey("KEY_YELLOW", Yellow_Key, 0x32, 6);
  addKey("KEY_BLUE", Blue_Key, 0x34, 6);
  addKey("KEY_GREEN", Green_Key, 0x36, 6);
  addKey("KEY_RED", Red_Key, 0x37, 6);
}


LGTV2b::LGTV2b(
  unsigned int index)
  : LGTV2(index)
{
  setKeysetName("TV Keyset 2b");
}


void LGTV2b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LGTV2::populateProtocol(guiObject);

  addKey("sleep", Sleep_Key, 0x26, 6); // might need separate class
  addKey("Q.VIEW", Unmapped_Key, 0x32, 6);
  addKey("LIST", Unmapped_Key, 0x34, 6);
  addKey("I/II/*", Audio_Key, 0x36, 6);
  addKey("EYE/*", Unmapped_Key, 0x37, 6);
}


LGHT1::LGHT1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Home Theater Keyset 1",
      LG_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void LGHT1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0x2222, 16);

  addKey("play", Play_Key, 0x04, 8);
  addKey("stop", Stop_Key, 0x05, 8);
  addKey("skip/next track", Next_Key, 0x06, 8);
  addKey("skip/prev track", Previous_Key, 0x07, 8);
  addKey("vol down", VolumeDown_Key, 0x16, 8);
  addKey("vol up", VolumeUp_Key, 0x17, 8);
  addKey("power", Power_Key, 0x1E, 8);
  addKey("mute", Mute_Key, 0x1F, 8);
  addKey("sound effect", Unmapped_Key, 0x2F, 8);
  addKey("1", One_Key, 0x41, 8);
  addKey("2", Two_Key, 0x42, 8);
  addKey("3", Three_Key, 0x43, 8);
  addKey("4", Four_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("7", Seven_Key, 0x47, 8);
  addKey("8", Eight_Key, 0x48, 8);
  addKey("9", Nine_Key, 0x49, 8);
  addKey("0", Zero_Key, 0x4B, 8);
  addKey("repeat", Repeat_Key, 0x4E, 8);
  addKey("pause", Pause_Key, 0x4F, 8);
  addKey("scan forward", FastForward_Key, 0x52, 8);
  addKey("scan back", Rewind_Key, 0x53, 8);
  addKey("speaker level", Unmapped_Key, 0x66, 8);
  addKey("R", Red_Key, 0x6C, 8);
  addKey("G", Green_Key, 0x6D, 8);
  addKey("Y", Yellow_Key, 0x6E, 8);
  addKey("B", Blue_Key, 0x6F, 8);
  addKey("record", Record_Key, 0x83, 8);
  addKey("radio&input", Input_Key, 0x8A, 8);
  addKey("open/close", Eject_Key, 0x9A, 8);
  addKey("back", Exit_Key, 0xA2, 8);
  addKey("info/display", Info_Key, 0xA3, 8);
  addKey("disc menu", DiscMenu_Key, 0xA4, 8);
  addKey("home", Menu_Key, 0xA5, 8);
  addKey("down arrow", Down_Key, 0xA6, 8);
  addKey("up arrow", Up_Key, 0xA7, 8);
  addKey("left arrow", Left_Key, 0xA8, 8);
  addKey("right arrow", Right_Key, 0xA9, 8);
  addKey("enter", Select_Key, 0xAA, 8);
  addKey("title/pop-up", DiscTitle_Key, 0xAF, 8);
  addKey("clear", Unmapped_Key, 0xB0, 8);
  addKey("search", Unmapped_Key, 0xB3, 8);
  addKey("marker", Unmapped_Key, 0xB4, 8);
  addKey("optical", Unmapped_Key, 0xB6, 8);
  addKey("sleep", Sleep_Key, 0xC2, 8);
}


LGHT2::LGHT2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Home Theater / BD Keyset 2",
      LG_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void LGHT2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0xC2C2, 16);

  addKey("power", Power_Key, 0x30, 8);
  addKey("play", Play_Key, 0x31, 8);
  addKey("rewind", Rewind_Key, 0x32, 8);
  addKey("fast fwd", FastForward_Key, 0x33, 8);
  addKey("channel up", ChannelUp_Key, 0x34, 8);
  addKey("next track", Next_Key, 0x34, 8);
  addKey("channel down", ChannelDown_Key, 0x35, 8);
  addKey("prev track", Previous_Key, 0x35, 8);
  addKey("eject", Eject_Key, 0x36, 8);
  addKey("Slow Fwd 1/16x", SlowPlus_Key, 0x37, 8);
  addKey("pause", Pause_Key, 0x38, 8);
  addKey("stop", Stop_Key, 0x39, 8);
  addKey("display", Info_Key, 0x3A, 8);
  addKey("1", One_Key, 0x3B, 8);
  addKey("2", Two_Key, 0x3C, 8);
  addKey("3", Three_Key, 0x3D, 8);
  addKey("4", Four_Key, 0x3E, 8);
  addKey("5", Five_Key, 0x3F, 8);
  addKey("6", Six_Key, 0x40, 8);
  addKey("7", Seven_Key, 0x41, 8);
  addKey("8", Eight_Key, 0x42, 8);
  addKey("9", Nine_Key, 0x43, 8);
  addKey("0", Zero_Key, 0x44, 8);
  addKey("exit", Exit_Key, 0x45, 8); // "return"
  addKey("blue", Blue_Key, 0x46, 8);
  addKey("clear", Clear_Key, 0x46, 8);
  addKey("up arrow", Up_Key, 0x47, 8);
  addKey("down arrow", Down_Key, 0x48, 8);
  addKey("green", Green_Key, 0x4A, 8);
  addKey("title", DiscTitle_Key, 0x4A, 8);
  addKey("DVD MENU", DiscMenu_Key, 0x4B, 8); // "list"
  addKey("ANGLE", Angle_Key, 0x4C, 8);
  addKey("audio", Audio_Key, 0x4F, 8);
  addKey("subtitle", Captions_Key, 0x50, 8);
  addKey("RANDOM", Random_Key, 0x51, 8);
  addKey("red", Red_Key, 0x53, 8);
  addKey("repeat", Repeat_Key, 0x53, 8);
  addKey("teletxt", Teletext_Key, 0x54, 8);
  addKey("A-B", RepeatAB_Key, 0x55, 8);
  addKey("menu", Menu_Key, 0x56, 8);
  addKey("PROGRAM", Unmapped_Key, 0x57, 8);
  addKey("select", Select_Key, 0x58, 8);
  addKey("left arrow", Left_Key, 0x59, 8);
  addKey("right arrow", Right_Key, 0x5A, 8);
  addKey("*", Unmapped_Key, 0x5E, 8);
  addKey("Slow Rev 1/16x", SlowMinus_Key, 0x60, 8);
  addKey("yellow", Yellow_Key, 0x61, 8); // "MARKER"
  addKey("search", Unmapped_Key, 0x62, 8);
  addKey("ZOOM", Zoom_Key, 0x64, 8);
  addKey("home", Unmapped_Key, 0x67, 8);
  addKey("favourite", Favorites_Key, 0x74, 8);
  addKey("Power ON", PowerOn_Key, 0x75, 8);
  addKey("Power OFF", PowerOff_Key, 0x76, 8);
  addKey("ProgramUp", Unmapped_Key, 0x77, 8);
  addKey("ProgramDown", Unmapped_Key, 0x78, 8);
  addKey("Lock", Unmapped_Key, 0x79, 8);
  addKey("inputnext", Input_Key, 0xB0, 8);
  addKey("record", Record_Key, 0xB6, 8);
  addKey("timer rec", RecordTimed_Key, 0xB7, 8);
  addKey("TimeShift", Unmapped_Key, 0xB9, 8);
  addKey("TV/DVD", AntennaInput_Key, 0xBE, 8);
  addKey("inputdvd", DVDInput_Key, 0xF1, 8);
  addKey("inputhdd", HDDInput_Key, 0xF2, 8);
  addKey("ProgramList", Unmapped_Key, 0xF4, 8);
}


void LGHT2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("TV / DVD", QVariant(AntennaInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("HDD", QVariant(HDDInput_Key));
}


LGHT2a::LGHT2a(
  unsigned int index)
  : LGHT2(index)
{
  setKeysetName("Home Theater / BD Keyset 2a");
}


void LGHT2a::populateProtocol(
  QObject *guiObject)
{
  LGHT2::populateProtocol(guiObject);

  addKey("A (Red)", Red_Key, 0x7C, 8);
  addKey("B (Green)", Green_Key, 0x7D, 8);
  addKey("C (Blue)", Blue_Key, 0x7E, 8);
  addKey("D (Yellow)", Yellow_Key, 0x7F, 8);
  addKey("Rew 100x", Unmapped_Key, 0x91, 8);
  addKey("Rew 16x", Unmapped_Key, 0x92, 8);
  addKey("Rew 4x", Unmapped_Key, 0x95, 8);
  addKey("Rew 2x", Unmapped_Key, 0x96, 8);
  addKey("Fwd 2x", Unmapped_Key, 0x99, 8);
  addKey("Fwd 4x", Unmapped_Key, 0x9B, 8);
  addKey("Fwd 16x", Unmapped_Key, 0x9D, 8);
  addKey("Fwd 100x", Unmapped_Key, 0x9F, 8);
  addKey("Z: Mp1", Unmapped_Key, 0xDE, 8);
  addKey("Z: Factory Reset !!!", Unmapped_Key, 0xDF, 8);
  addKey("Z: CPRM DATA READ/SAVE", Unmapped_Key, 0xE0, 8);
  addKey("Z: TECHNICAL MENU", Unmapped_Key, 0xE1, 8);
  addKey("Z: INTERLACE/PROG SCAN", Unmapped_Key, 0xE2, 8);
  addKey("Z: service menu", Unmapped_Key, 0xE5, 8);
  addKey("Resolution", AspectRatio_Key, 0xF5, 8);
  addKey("Subtitle on-off", Unmapped_Key, 0xF7, 8);
  addKey("Pic Mode", PictureMode_Key, 0xF9, 8);
  addKey("Music ID - ID", Unmapped_Key, 0xFA, 8);
}


LGDisc1::LGDisc1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD/BD Keyset 1",
      LG_Make,
      MediaControl_Panels,
      index)
{
}


void LGDisc1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0x2C2C, 16);

  addKey("cd-dvd", CDInput_Key, 0x03, 8);
  addKey("play", Play_Key, 0x04, 8);
  addKey("stop", Stop_Key, 0x05, 8);
  addKey("<<<", Next_Key, 0x06, 8);
  addKey(">>>", Previous_Key, 0x07, 8);
  addKey("aux", AuxInput_Key, 0x09, 8);
  addKey("minus", Unmapped_Key, 0x12, 8);  // "pr_preset_down"
  addKey("plus", Unmapped_Key, 0x13, 8); // "pr_preset_up"
  addKey("volume-", VolumeDown_Key, 0x16, 8);
  addKey("volume+", VolumeUp_Key, 0x17, 8);
  addKey("power", Power_Key, 0x1E, 8);
  addKey("mute", Mute_Key, 0x1F, 16);
  addKey("pty-search", Unmapped_Key, 0x39, 8);
  addKey("1", One_Key, 0x41, 8);
  addKey("2", Two_Key, 0x42, 8);
  addKey("3", Three_Key, 0x43, 8);
  addKey("4", Four_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("7", Seven_Key, 0x47, 8);
  addKey("8", Eight_Key, 0x48, 8);
  addKey("9", Nine_Key, 0x49, 8);
  addKey("0", Zero_Key, 0x4B, 8);
  addKey("program", Program_Key, 0x4D, 8);
  addKey("repeat", Repeat_Key, 0x4E, 8);
  addKey("pause", Pause_Key, 0x4F, 8);
  addKey("band", ToggleBand_Key, 0x59, 8);
  addKey("dimmer", Unmapped_Key, 0x5E, 8);
  addKey("rds", RDS_Key, 0x60, 8);
  addKey("exit_cancel", Unmapped_Key, 0x69, 8);
  addKey("caption", Captions_Key, 0x6A, 8);
  addKey("guide", Guide_Key, 0x6B, 8);
  addKey("pty", Unmapped_Key, 0x71, 8);
  addKey("i_ii", Unmapped_Key, 0x7A, 8);
  addKey("text", Unmapped_Key, 0x7B, 8);
  addKey("tv_radio", Input_Key, 0x82, 8);
//  addKey("aux", Unmapped_Key, 0x8A, 8);
  addKey("open-close", Eject_Key, 0x9A, 8);
  addKey("audio", Audio_Key, 0xA0, 8);
  addKey("sound", SoundMode_Key, 0xA1, 8);
  addKey("return", Exit_Key, 0xA2, 8);
  addKey("display", Info_Key, 0xA3, 8);
  addKey("menu", DiscMenu_Key, 0xA4, 8);
  addKey("setup", Menu_Key, 0xA5, 8);
  addKey("down", Down_Key, 0xA6, 8);
  addKey("up", Up_Key, 0xA7, 8);
  addKey("left", Left_Key, 0xA8, 8);
  addKey("right", Right_Key, 0xA9, 8);
  addKey("enter", Select_Key, 0xAA, 8);
  addKey("s-title", Unmapped_Key, 0xAB, 8);
  addKey("angle", Angle_Key, 0xAC, 8);
  addKey("repeata-b", RepeatAB_Key, 0xAD, 8);
  addKey("zoom", Zoom_Key, 0xAE, 8);
  addKey("title", DiscTitle_Key, 0xAF, 8);
  addKey("clear", Clear_Key, 0xB0, 8);
  addKey("<<", Rewind_Key, 0xB1, 8);
  addKey(">>", FastForward_Key, 0xB2, 8);
  addKey("search", Unmapped_Key, 0xB3, 8);
  addKey("marker", Unmapped_Key, 0xB4, 8);
  addKey("sleep", Sleep_Key, 0xC2, 8);
}


void LGDisc1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("CD / DVD", QVariant(CDInput_Key));
  cb->addItem("TV / Radio", QVariant(Input_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
}


LGDisc2::LGDisc2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD/BD Keyset 2",
      LG_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(LG_Make, "DV552", DVD_Device);
}


void LGDisc2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0x2D2D, 16);

  addKey("POWER", Power_Key, 0x30, 8);
  addKey("PLAY", Play_Key, 0x31, 8);
  addKey("SCAN-BACK", Rewind_Key, 0x32, 8); // <<
  addKey("SCAN-FORWARD", FastForward_Key, 0x33, 8); // >>
  addKey("SKIP-FORWARD", Next_Key, 0x34, 16);  // >>|
  addKey("SKIP-BACK", Previous_Key, 0x35, 16); // |<<
  addKey("OPEN/CLOSE", Eject_Key, 0x36, 8);
  addKey("PAUSE", Pause_Key, 0x38, 8);
  addKey("STOP", Stop_Key, 0x39, 8);
  addKey("DISPLAY", Info_Key, 0x3A, 8);
  addKey("1", One_Key, 0x3B, 8);
  addKey("2", Two_Key, 0x3C, 8);
  addKey("3", Three_Key, 0x3D, 8);
  addKey("4", Four_Key, 0x3E, 8);
  addKey("5", Five_Key, 0x3F, 8);
  addKey("6", Six_Key, 0x40, 8);
  addKey("7", Seven_Key, 0x41, 8);
  addKey("8", Eight_Key, 0x42, 8);
  addKey("9", Nine_Key, 0x43, 8);
  addKey("0", Zero_Key, 0x44, 8);
  addKey("RETURN", Exit_Key, 0x45, 8);
  addKey("CLEAR", Clear_Key, 0x46, 8);
  addKey("UP", Up_Key, 0x47, 8);
  addKey("DOWN", Down_Key, 0x48, 8);
  addKey("TITLE", DiscTitle_Key, 0x4A, 8);
  addKey("DVD-MENU", DiscMenu_Key, 0x4B, 8);
  addKey("ANGLE", Angle_Key, 0x4C, 8);
  addKey("AUDIO", Audio_Key, 0x4F, 8);
  addKey("SUBTITLE", Captions_Key, 0x50, 8);
  addKey("RANDOM", Random_Key, 0x51, 8); // "cm-skip"
  addKey("REPEAT", Repeat_Key, 0x53, 8);
  addKey("A-B", RepeatAB_Key, 0x55, 8); // "lp"
  addKey("SETUP", Menu_Key, 0x56, 8);
  addKey("PROGRAM", Program_Key, 0x57, 8);
  addKey("ENTER", Select_Key, 0x58, 8); // "ok"
  addKey("LEFT", Left_Key, 0x59, 8);
  addKey("RIGHT", Right_Key, 0x5A, 8);
  addKey("STAR", Unmapped_Key, 0x5E, 8);
  addKey("KEY_PIP", PIP_Key, 0x5F, 8);
  addKey("MARKER", Unmapped_Key, 0x61, 8);
  addKey("SEARCH", Unmapped_Key, 0x62, 8); // "random"
  addKey("ZOOM", Zoom_Key, 0x64, 8);
  addKey("PowerOn", PowerOn_Key, 0x75, 8);
  addKey("PowerOff", PowerOff_Key, 0x76, 8);
  addKey("DVD", Unmapped_Key, 0xF1, 8);
  addKey("KEY_RESOLUTION", AspectRatio_Key, 0xF5, 8);
}


LGDisc2a::LGDisc2a(
  unsigned int index)
  : LGDisc2(index)
{
  setKeysetName("DVD/BD Keyset 2a");
}


void LGDisc2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LGDisc2::populateProtocol(guiObject);

  addKey("KEY_HOME", Menu_Key, 0x67, 8);
  addKey("KEY_CLEAR", Clear_Key, 0x7C, 8);
  addKey("KEY_RED", Red_Key, 0x7C, 8);
  addKey("KEY_GREEN", Green_Key, 0x7D, 8);
  addKey("KEY_YELLOW", Yellow_Key, 0x7E, 8);
  addKey("KEY_BLUE", Blue_Key, 0x7F, 8);
}


LGVCR1::LGVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      LG_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void LGVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);
  threadableProtocol->setMinimumRepetitions(1);

  setPreData(0x6E, 8);

  addKey("eject", Eject_Key, 0x00, 8);
  addKey("stop", Stop_Key, 0x01, 8);
  addKey("rew", Rewind_Key, 0x02, 8);
  addKey("ff", FastForward_Key, 0x03, 8);
  addKey("0", Zero_Key, 0x04, 8);
  addKey("1", One_Key, 0x05, 8);
  addKey("2", Two_Key, 0x06, 8);
  addKey("3", Three_Key, 0x07, 8);
  addKey("play", Play_Key, 0x08, 8);
  addKey("rec", Record_Key, 0x09, 8);
  addKey("p/still", Pause_Key, 0x0B, 8);
  addKey("4", Four_Key, 0x0C, 8);
  addKey("5", Five_Key, 0x0D, 8);
  addKey("6", Six_Key, 0x0E, 8);
  addKey("7", Seven_Key, 0x0F, 8);
  addKey("power", Power_Key, 0x14, 8);
  addKey("tv/vcr", Input_Key, 0x15, 8);
  addKey("menu", Menu_Key, 0x16, 8);  // "setup", "I"
  addKey("pr+", ChannelUp_Key, 0x18, 8);
  addKey("pr+", Up_Key, 0x18, 8);
  addKey("pr-", ChannelDown_Key, 0x19, 8);
  addKey("pr-", Down_Key, 0x19, 8);
  addKey("8", Eight_Key, 0x1C, 8);
  addKey("9", Nine_Key, 0x1D, 8);
  addKey("ok", Select_Key, 0x1E, 8);
  addKey("clear/reset", Clear_Key, 0x1F, 8);  // might be wrong
  addKey("timer-prog", Program_Key, 0x3A, 8);
  addKey("viss", IndexSearch_Key, 0x41, 8); // "marker-search"
  addKey("trk-", TrackingMinus_Key, 0x44, 8);
  addKey("trk+", TrackingPlus_Key, 0x45, 8);
  addKey("*", Unmapped_Key, 0x47, 8);
  addKey("lp", VHSSpeed_Key, 0x48, 8);
  addKey("clock/count", Clock_Key, 0x4C, 8);
  addKey("tv/av", Unmapped_Key, 0x56, 8);
  addKey("vol+", VolumeUp_Key, 0x58, 8);
  addKey("vol+", Right_Key, 0x58, 8);
  addKey("vol-", VolumeDown_Key, 0x59, 8);
  addKey("vol-", Left_Key, 0x59, 8);
  addKey("sleep", Sleep_Key, 0x5C, 8);
  addKey("mute", Mute_Key, 0x5D, 8);
  addKey("auto", AutoTracking_Key, 0x5F, 8); // "A.TRK"
  addKey("qview", Unmapped_Key, 0x77, 8);
  addKey("repeat", Repeat_Key, 0xB6, 8);
  addKey("ez_POWER_OFF", PowerOff_Key, 0xB8, 8);
  addKey("audio", Audio_Key, 0xC1, 8);
  addKey("c/lock", Unmapped_Key, 0xCF, 8);
  addKey("system", Unmapped_Key, 0xDC, 8);
  addKey("VCR", Unmapped_Key, 0xF1, 8);
  addKey("cm-skip", Unmapped_Key, 0xDD, 8);
}


LGVCR1a::LGVCR1a(
  unsigned int index)
  : LGVCR1(index)
{
  setKeysetName("VCR Keyset 1a");
}


void LGVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LGVCR1::populateProtocol(guiObject);

  addKey("power", Power_Key, 0x7D, 8);
}


LGVCR1b::LGVCR1b(
  unsigned int index)
  : LGVCR1(index)
{
  setKeysetName("VCR Keyset 1b");
}


void LGVCR1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LGVCR1::populateProtocol(guiObject);

  addKey("menu-up", Up_Key, 0x82, 8);
  addKey("menu-left", Left_Key, 0x83, 8);
  addKey("menu-down", Down_Key, 0x89, 8);
  addKey("ok", Select_Key, 0x8E, 8);
  addKey("menu-right", Right_Key, 0x90, 8);
}


LGAC1::LGAC1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Air Conditioner 1",
      LG_Make,
      ACFan_Panels,
      index)
{
}


void LGAC1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);
  threadableProtocol->setMinimumRepetitions(1);

  setPreData(0x6681, 16);

  addKey("power", Power_Key, 0x81, 8);
  addKey("temp up", TempUp_Key, 0x85, 8);
  addKey("temp down", TempDown_Key, 0x8A, 8);
  addKey("timer", Timer_Key, 0x90, 8);
  addKey("fan speed", FanFaster_Key, 0x99, 8);
  addKey("mode", Mode_Key, 0x9B, 8);
}
