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

## About
sleepwipe is an open-source package that prevents the computer from going to sleep on macOS.

## To Do List (Open Source Participation)
| To Do | To Do Description | To Do Status |
| --- | --- | --- |
| parser | Parsing the incoming input and making it usable by the router. | under construction by cagriyalniz |
| get data | Getting last commit date from GithubAPI | finished by fleizean |
| time sleep | sleep until the input time | under construction by fleizean |
| process sleep | sleep until the process ends | Active but waiting parser |

## Build

    git clone https://github.com/fleizean/sleepwipe.git
    cd sleepwipe
    export PATH=$PATH:/currentarea/sleepwipe/
    sleepwipe -help
