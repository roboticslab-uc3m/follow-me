## Follow-me demonstration: Installation from Source Code

First install the dependencies:
- [Install CMake](https://github.com/roboticslab-uc3m/installation-guides/blob/master/install-cmake.md)
- [Install YARP](https://github.com/roboticslab-uc3m/installation-guides/blob/master/install-yarp.md)
- [Install YARP-DEVICES](https://github.com/roboticslab-uc3m/yarp-devices/blob/develop/doc/yarp_devices_install_on_debian_6.md)
- [Install VISION](https://github.com/roboticslab-uc3m/vision/blob/develop/doc/vision-install.md)
- [Install SPEECH](https://github.com/roboticslab-uc3m/speech/blob/develop/doc/speech-install.md)

### Install follow-me demo on Ubuntu

Our software integrates the previous dependencies. Note that you will be prompted for your password upon using `sudo` a couple of times:

```bash
cd  # go home
mkdir -p repos; cd repos  # create $HOME/repos if it does not exist; then, enter it
git clone https://github.com/roboticslab-uc3m/follow-me.git  # Download follow-me demostration software from the repository
cd follow-me; mkdir build; cd build; cmake ..  # Configure the follow-me demostration software
make -j$(nproc)  # Compile
sudo make install  # Install :-)
cp ../scripts/gnome/follow-me.desktop $HOME/Desktop  # Nice desktop icon. May require some updates to point to path and icon.
```
For additional options use `ccmake` instead of `cmake`.
