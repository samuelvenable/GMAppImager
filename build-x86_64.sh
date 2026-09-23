cd "${0%/*}";
x86_64-linux-gnu-g++ GMAppImager.cpp GMAppImager-x86_64/libdlgmod.a GMAppImager-x86_64/libfilesystem.a GMAppImager-x86_64/libxprocess.a `pkg-config --cflags --libs x11 dbus-1` -I. -o GMAppImager-x86_64/GMAppImager;
