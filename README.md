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
  <a href="https://discord.gg/MJnYWKSYNq">
    <img src="https://img.shields.io/discord/1099995968398696519?color=%235865F2&logo=discord&logoColor=%23FFFFFF&style=for-the-badge">
  </a>
  <a href="https://github.com/fleizean/sleepwipe/issues">
    <img src="https://img.shields.io/github/issues-raw/fleizean/sleepwipe?style=for-the-badge">
  </a>
</div>

# Video Preview
[![Preview](https://img.youtube.com/vi/TexHTlw6Z7c/0.jpg)](https://www.youtube.com/watch?v=TexHTlw6Z7c)


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
| keyboard(some keyboard keys) or mouse click sleep | Prevent sleep until you touch some keyboard keys or mouse click | Active | None |
| set a password sleep | Do not end the sleep until the designated password is entered. | Claimed | [fyurtsev](https://github.com/fyurtsev) |

## Build

    git clone https://github.com/fleizean/sleepwipe.git || cd sleepwipe || make
    export PATH=$PATH:~/<current_dir>/sleepwipe/ -> example export PATH=$PATH:~/Desktop/sleepwipe/
    sleepwipe -h
