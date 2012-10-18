/*
 * Copyright (C) 2012  Fernando García  <fernando.garli@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
   
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "SGApplication.hxx"

/**
 * Allocate memory and initialize variables. argc and argv are given so the user
 * can use them or not, but it is not compulsory.
 */
SGApplication::SGApplication(int argc, char **argv) :
     m_quit_flag(false),
     m_subsystem_mgr(NULL)
{
     m_subsystem_mgr = new SGSubsystemMgr;
}

/**
 * Free previously allocated memory (check for NULL; only free if it is NOT
 * NULL). A case where a pointer can still be NULL can occur when the user
 * interrupted the program before the constructor gets executed.
 */
SGApplication::~SGApplication()
{
     if (!m_subsystem_mgr) delete m_subsystem_mgr;
}

/**
 * Run the main loop until 'm_quit_flag' is true.
 * This simple main loop updates all the subsystems (by updating the subsystem
 * manager). The update function actually needs the delta time, but FGRadar
 * doesn't need a lot of resources and it isn't a heavy 3D program, so passing 0
 * is a good solution.
 */
void
SGApplication::run()
{
     while (!m_quit_flag) {

          // Update subsystems
          m_subsystem_mgr->update(0);
     }
}

/**
 * Quit the program by setthing 'm_quit_flag' to true.
 * In the future, some things might be added, that's why it is recommended to
 * call this function instead of changing 'm_quit_flag' manually.
 */
void
SGApplication::quit()
{
     m_quit_flag = true;
}
