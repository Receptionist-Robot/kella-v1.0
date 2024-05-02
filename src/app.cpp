
/******************************************************************************

    C++ Script License - Version 1.0
    Author: Gayan Brahmanage, Ph.D.
    Contact: gayansampathefac@gmail.com
    LinkedIn: https://www.linkedin.com/in/gayan-brahmanage/
    GitHub: https://github.com/gayanbrahmanage

    This C++ script is licensed under the terms of the MIT license. Please see
    the following terms and conditions:

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

******************************************************************************/

#include "gui.h"
#include "esp32.h"
#include "joystick.h"

int main(int argc, char **argv){

  auto app = Gtk::Application::create(argc, argv, "GayanBrahmanage");
  gui kella_gui;

  esp32* master=new esp32();
  std::thread master_thread(&esp32::run,master,kella_gui.msg,&kella_gui);

  joystick* jstick=new joystick();
  std::thread jstick_thread(&joystick::read,jstick,kella_gui.msg,&kella_gui);

  app->run(kella_gui);

  master_thread.join();
  jstick_thread.join();
  return 0;
}