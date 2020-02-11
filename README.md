# OOP 2020

1. Install dev tools and git and your favorite editor (emacs/vs code for me). These are installed by default in desk18
1. Create a private repository for this course on github, it should be called ai-mavuser, so the url to the new repo is `https://github.com/gituser/oop-mavuser`
1. Clone this repository (oop-spring2020-public) and your repository (oop-mavuser) locally.  I work in the `~/projects` directory.
1. Install conda (desk18 has that installed as well)
1. Create a local envirnoment for python using python
```bash
conda create -p env python=3.8

```
1. Copy py3hello from my wmacevoy/csci000-astudent project to your project
```bash
cp -r ../oop-spring2020-public/py3hello .
```
1. To activate the virtual environment in the project directory
```bash
conda activate ./env
```
1. From there you should be able to run the hello test in the project directory
```bash
py3hello/hellotest/hellotest.py
```

From a terminal with the local conda environment activated


# WSL

For windows / direct unix users, you can install tools on your own.  You will lose the ability to make snapshots, and may have more trouble getting a proper execution environment.  You will have a very poor experience with a chromebook, since the Visual Studio Code plugins for python will not work in that environment.

These notes from Dr. Banet may help: https://docs.google.com/document/d/1tDQrLuCJslEO-ooCj1JTUlkySM3-XcxNqK8DQ3f1ld8/edit

- Install Conda
- Install WSL
- In WLS
```bash
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install git cmake build-essential emacs curl
```

These environments are not tested by me.


| Assignment  | Link  | Notes  |
|---|---|---|
| 1  | [bicycle](https://github.com/wmacevoy/oop-spring2020-public/tree/master/bicycle)  | Done
