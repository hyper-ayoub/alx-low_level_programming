# 0x1C. C - Makefiles:



![giphy-2](https://github.com/hyper-ayoub/alx-low_level_programming/assets/133155846/7a7bee6c-b7fa-4387-82aa-7eb4b7d78583)

1.what mean makefiles:


A Makefile is a special file that contains rules and dependencies used by the make utility to build and manage projects. The primary purpose of a Makefile is to automate the build process of a software project by specifying how different components of the project depend on each other and how they should be built.

Installing the make utility:


                               sudo apt update
                               
                               sudo apt install make

Check:


                            make --version

                            ls /usr/bin/make


!!.PHONY 

In a Makefile, the .PHONY target is used to declare targets that are not associated with actual files. These targets are often used for actions that don't produce a file as output, such as cleaning or rebuilding the project. Here's a breakdown of each :

                          .PHONY: all clean oclean fclean re












