if [ "$EUID" -ne 0 ]
then
    echo "Please run as root"
else
    condition=$(which cmake 2>/dev/null | grep -v "not found" | wc -l)
    if [ $condition -eq 0 ] ; then
	tar -xf cmake-3.9.0-rc3.tar
	cd cmake-3.9.0-rc3
	./bootstrap
	make -j4
	sudo make install
    fi

    save=$(pwd)
    mv -f irrlicht-1.8.4 /usr/lib/
    cd /usr/lib/irrlicht-1.8.4
    cd source/Irrlicht && make -j4
    cd ../.. && cp -r include/* /usr/local/include/ && cp lib/Linux/libIrrlicht.a /usr/local/lib

    apt-get install libglew-dev libsdl2-dev libsdl2-image-dev libglm-dev libfreetype6-dev build-essential libgl1-mesa-dev # Debian, Ubuntu
    dnf install glew-devel SDL2-devel SDL2_image-devel glm-devel freetype-devel   # Fedora
    pacman -S glew sdl2 sdl2_image glm freetype2 mesa

    cd $save
    chmod 755 compile.sh
    ./compile.sh
    exit
fi
