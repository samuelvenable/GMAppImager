/*

MIT License

Copyright © 2026 Samuel Venable

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <libdlgmod.hpp>
#include <libfilesystem.hpp>
#include <libxprocess.hpp>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
static std::string filename_name(std::string fname) {
  size_t fp = fname.find_last_of("/");
  return fname.substr(fp + 1);
}
static std::string string_replace_all(std::string str, std::string substr, std::string nstr) {
  size_t pos = 0;
  while ((pos = str.find(substr, pos)) != std::string::npos) {
    str.replace(pos, substr.length(), nstr);
    pos += nstr.length();
  }
  return str;
}
static std::vector<std::string> string_split(std::string str, char delimiter) {
  std::vector<std::string> vec;
  std::stringstream sstr(str);
  std::string tmp;
  while (std::getline(sstr, tmp, delimiter))
    vec.push_back(tmp);
  return vec;
}
int main() {
std::vector<std::string> blacklist_array;
blacklist_array.push_back("ld-linux.so.2");
blacklist_array.push_back("ld-linux-armhf.so.3");
blacklist_array.push_back("ld-linux-x86-64.so.2");
blacklist_array.push_back("ld-linux-aarch64.so.1");
blacklist_array.push_back("libanl.so.1");
blacklist_array.push_back("libBrokenLocale.so.1");
blacklist_array.push_back("libcidn.so.1");
blacklist_array.push_back("libc.so.6");
blacklist_array.push_back("libdl.so.2");
blacklist_array.push_back("libm.so.6");
blacklist_array.push_back("libmvec.so.1");
blacklist_array.push_back("libnss_compat.so.2");
blacklist_array.push_back("libnss_dns.so.2");
blacklist_array.push_back("libnss_files.so.2");
blacklist_array.push_back("libnss_hesiod.so.2");
blacklist_array.push_back("libnss_nisplus.so.2");
blacklist_array.push_back("libnss_nis.so.2");
blacklist_array.push_back("libpthread.so.0");
blacklist_array.push_back("libresolv.so.2");
blacklist_array.push_back("librt.so.1");
blacklist_array.push_back("libthread_db.so.1");
blacklist_array.push_back("libutil.so.1");
blacklist_array.push_back("libstdc++.so.6");
blacklist_array.push_back("libGL.so.1");
blacklist_array.push_back("libEGL.so.1");
blacklist_array.push_back("libGLdispatch.so.0");
blacklist_array.push_back("libGLX.so.0");
blacklist_array.push_back("libOpenGL.so.0");
blacklist_array.push_back("libdrm.so.2");
blacklist_array.push_back("libglapi.so.0");
blacklist_array.push_back("libgbm.so.1");
blacklist_array.push_back("libxcb.so.1");
blacklist_array.push_back("libX11.so.6");
blacklist_array.push_back("libgio-2.0.so.0");
blacklist_array.push_back("libasound.so.2");
blacklist_array.push_back("libfontconfig.so.1");
blacklist_array.push_back("libthai.so.0");
blacklist_array.push_back("libfreetype.so.6");
blacklist_array.push_back("libharfbuzz.so.0");
blacklist_array.push_back("libcom_err.so.2");
blacklist_array.push_back("libexpat.so.1");
blacklist_array.push_back("libgcc_s.so.1");
blacklist_array.push_back("libglib-2.0.so.0");
blacklist_array.push_back("libgpg-error.so.0");
blacklist_array.push_back("libICE.so.6");
blacklist_array.push_back("libp11-kit.so.0");
blacklist_array.push_back("libSM.so.6");
blacklist_array.push_back("libusb-1.0.so.0");
blacklist_array.push_back("libuuid.so.1");
blacklist_array.push_back("libz.so.1");
blacklist_array.push_back("libgobject-2.0.so.0");
blacklist_array.push_back("libpangoft2-1.0.so.0");
blacklist_array.push_back("libpangocairo-1.0.so.0");
blacklist_array.push_back("libpango-1.0.so.0");
blacklist_array.push_back("libgpg-error.so.0");
blacklist_array.push_back("libjack.so.0");
blacklist_array.push_back("libxcb-dri3.so.0");
blacklist_array.push_back("libxcb-dri2.so.0");
blacklist_array.push_back("libfribidi.so.0");
blacklist_array.push_back("libgmp.so.10");
std::string systemfolder; std::string game_display_name = "GMAppImager";
int uname = ProcessExecute((char *)"uname -i"); std::string unameoutput = ExecutedProcessReadFromStandardOutput(uname);
unameoutput = string_replace_all(unameoutput, "\r", ""); unameoutput = string_replace_all(unameoutput, "\n", "");
if (unameoutput == "i386") { systemfolder = "i386-linux-gnu"; } else if (unameoutput == "x86_64") { systemfolder = "x86_64-linux-gnu"; }
else if (unameoutput == "armv7l" || unameoutput == "unknown") { systemfolder = "arm-linux-gnueabihf"; } else if (unameoutput == "aarch64") { systemfolder = "aarch64-linux-gnu"; }
FreeExecutedProcessStandardOutput(uname); FreeExecutedProcessStandardInput(uname);
std::string e = get_open_filename_ext("", "", environment_get_variable((char *)"HOME"), "Select Linux GameMaker Game Unix Executable...");
if (e == "") { directory_destroy((char *)("${HOME}/.config/" + game_display_name).c_str()); exit(0); }
std::string icon = get_open_filename_ext("PNG Icon Files (*.png)|*.png", "", environment_get_variable((char *)"HOME"), "Select Linux AppImage PNG Icon File...");
if (icon == "") { directory_destroy((char *)("${HOME}/.config/" + game_display_name).c_str()); exit(0); }
std::string d = get_directory_alt("Select Linux GameMaker Game Assets Directory...", environment_get_variable((char *)"HOME"));
if (d == "") { directory_destroy((char *)("${HOME}/.config/" + game_display_name).c_str()); exit(0); }
while (!d.empty() && d.find_last_of("/") == d.length() - 1 && d != "/") { d = d.substr(0, d.length() - 1); }
std::vector<int> p; p.push_back(ProcessExecute((char *)("ldd \"" + e + "\"").c_str()));
for (int s = 0; s < p.size(); s++) {
  std::vector<std::string> a = string_split(ExecutedProcessReadFromStandardOutput(p[s]), '\n');
  for (int i = 0; i < a.size(); i++) {
    std::vector<std::string> b = string_split(a[i], ' ');
    for (int j = 0; j < b.size(); j++) {
      if (j == 2) {
        file_copy((char *)b[j].c_str(), (char *)("${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/lib/" + systemfolder + "/" + filename_name(b[j])).c_str());
        for (int t = 0; t < blacklist_array.size(); t++) {
          if (!filename_name(b[j]).compare(blacklist_array[t])) {
            file_delete((char *)("${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/lib/" + systemfolder + "/" + filename_name(b[j])).c_str());
          }
        }
      }
    }
  }
}
std::vector<std::string> f;
f.push_back(directory_contents_first((char *)d.c_str(), (char *)"*.so;*.elf", false, true));
while (!f.empty() && f.back() != "") {
  p.push_back(ProcessExecute((char *)("ldd \"" + f.back() + "\"").c_str()));
  for (int s = 0; s < p.size(); s++) {
    std::vector<std::string> a = string_split(ExecutedProcessReadFromStandardOutput(p[s]), '\n');
    for (int i = 0; i < a.size(); i++) {
      std::vector<std::string> b = string_split(a[i], ' ');
      for (int j = 0; j < b.size(); j++) {
        if (j == 2) {
          file_copy((char *)b[j].c_str(), (char *)("${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/lib/" + systemfolder + "/" + filename_name(b[j])).c_str());
          for (int t = 0; t < blacklist_array.size(); t++) {
            if (!filename_name(b[j]).compare(blacklist_array[t])) {
              file_delete((char *)("${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/lib/" + systemfolder + "/" + filename_name(b[j])).c_str());
            }
          }
        }
      }
    }
  }
  f.push_back(directory_contents_next());
}
directory_contents_close();
file_copy((char *)(std::string(executable_get_directory()) + "assets/application.appdir/apprun").c_str(), (char *)("${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/AppRun").c_str());
system(("chmod u+x \"${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/AppRun\"").c_str());
file_copy((char *)(std::string(executable_get_directory()) + "assets/application.appdir/executable.desktop").c_str(), (char *)("${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/executable.desktop").c_str());
file_copy((char *)icon.c_str(), (char *)("${HOME}/.config/" + game_display_name+ "/assets/Application.AppDir/icon.png").c_str());
file_copy((char *)e.c_str(), (char *)("${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/usr/bin/executable").c_str());
directory_copy((char *)d.c_str(), (char *)("${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/usr/bin/" + filename_name(d)).c_str());
file_copy((char *)(std::string(executable_get_directory()) + "assets/appimagetool.appimage").c_str(), (char *)("${HOME}/.config/" + game_display_name + "/assets/appimagetool.AppImage").c_str());
system(("chmod u+x \"${HOME}/.config/" + game_display_name + "/assets/appimagetool.AppImage\"").c_str());
system(("sed -i -e 's#/usr#././#g' \"${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/usr/bin/executable\"").c_str());
system(("chmod u+x \"${HOME}/.config/" + game_display_name + "/assets/Application.AppDir/usr/bin/executable\"").c_str());
system(("\"${HOME}/.config/" + game_display_name + "/assets/appimagetool.AppImage\" \"${HOME}/.config/" + game_display_name + "/assets/Application.AppDir\" \"${HOME}/.config/" + game_display_name + "/assets/Application.AppImage\"").c_str());
system(("chmod u+x \"${HOME}/.config/" + game_display_name + "/assets/Application.AppImage\"").c_str());
std::string o = get_save_filename_ext("AppImage Executable (*.AppImage)|*.AppImage", "Untitled.AppImage", environment_get_variable((char *)"HOME"), "Save As");
if (o == "") { directory_destroy((char *)("${HOME}/.config/" + game_display_name).c_str()); exit(0); }
file_copy((char *)("${HOME}/.config/" + game_display_name + "/assets/Application.AppImage").c_str(), (char *)o.c_str());
directory_destroy((char *)("${HOME}/.config/" + game_display_name).c_str());
system(("chmod u+x \"" + o + "\"").c_str());
return 0;
}







