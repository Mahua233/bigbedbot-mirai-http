#pragma once

////////////////////////////////////////////////////////////////////////////

//extern time_t banTime_me;

////////////////////////////////////////////////////////////////////////////
namespace core
{
int initialize();
int config();
int init_app_and_start();
int exit();

bool isBotStarted();
}