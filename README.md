# Godot Goatee

A Deep Learning library developed for the Godot Game Engine.

# Contributing to the library

## Setup the development environment

A huge thank you to Thoughtquake for his [C++ with Godot tutorial](https://www.youtube.com/watch?v=XPcSfXsoArQ&list=PLu-KuZM47vrnVl3Dv1LXcw5MJZIr6ETvi). Most of the steps were borrowed from him and slightly changed to suit my dev environment.

You will need to **install Visual Studio** together with the C++ development tools.

Then open a terminal in this folder and run
```
# pull all submodule dependencies
git submodule update --init --recursive

# create a virtual environment
python -m venv .env

# activate the Python environment
.env\Scripts\activate

# install scons to be able to build the library
pip install scons
```

## Build the godot-cpp library
**Note**: At the time of writing this, there is an [open issue](https://github.com/godotengine/godot/issues/62128) for building godot-cpp with anithing other than x64 Native Tools.

Because of this, you will need to open a **x64 Native Tools Command Prompt** and navigate to this folder.

Then run the following commands
```
# activate the Python environment
.env\Scripts\activate

# navigate to the godot-cpp folder
cd godot-cpp

# build godot-cpp using scons
scons target=release platform=windows generate_bindings=yes bits=64

# navigate to goatee-cpp folder
cd ../goatee-cpp

# build goatee binaries
scons target=release platform=windows
```

# ToDos
- [ ] Add instructions for how to setup xtensor with vcpkg
- [x] Add matrix loading into cpp
- [ ] Overwrite basic opperations between arrays (addition, subtraction etc.)
- [ ] Add ability to transpose matrix
- [ ] Implement np.vectorize