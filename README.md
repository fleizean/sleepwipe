<div align="center">
  <img src="img/logo-bg.png">
  <br>
  <a href="https://github.com/fleizean/sleepwipe/blob/main/LICENSE">
    <img src="https://img.shields.io/github/license/fleizean/sleepwipe?style=for-the-badge">
  </a>
  <a href="https://github.com/fleizean/sleepwipe/commits/main">
    <img src="https://img.shields.io/github/last-commit/fleizean/sleepwipe?style=for-the-badge">
  </a>
  <a href="https://github.com/fleizean/sleepwipe/network/members">
    <img src="https://img.shields.io/github/forks/fleizean/sleepwipe?style=for-the-badge">
  </a>
  <a href="https://github.com/fleizean/sleepwipe/issues">
    <img src="https://img.shields.io/github/issues-raw/fleizean/sleepwipe?style=for-the-badge">
  </a>
</div>

# Video Preview
<p align="center">
  <a href="https://www.youtube.com/watch?v=TexHTlw6Z7c">
    <img src="https://img.youtube.com/vi/TexHTlw6Z7c/0.jpg" alt="Preview">
  </a>
</p>


## About
sleepwipe is an open-source package that prevents the computer from going to sleep on macOS.

## To Do List (Open Source Participation)
You can specify that you will do it by editing the None and Active values ​​and throwing a pull request.

| To Do | To Do Description | To Do Status | Person To Do |
| --- | --- | --- | --- |
| parser | Parsing the incoming input and making it usable by the router. | Finished ✅ | [fleizean](https://github.com/fleizean) |
| get data | Getting last commit date from GithubAPI | Finished ✅ | [fleizean](https://github.com/fleizean) |
| time sleep | Prevent sleep until the input time | Finished ✅ | [fleizean](https://github.com/fleizean) |
| process sleep | Prevent sleep until given process is finished | Finished ✅ | [fyurtsev](https://github.com/fyurtsev) |

## Build Insallation I
    git clone https://github.com/fleizean/sleepwipe.git || cd sleepwipe || make
    export PATH=$PATH:~/<current_dir>/sleepwipe/ -> example export PATH=$PATH:~/Desktop/sleepwipe/
    sleepwipe -h
  ### Build Insallation II
  ```bash
  sh -c "$(curl https://raw.githubusercontent.com/fleizean/sleepwipe/main/install.sh)"
  ```