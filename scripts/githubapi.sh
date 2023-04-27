#!/bin/bash
MANGENTA="\033[35m"
BOLD="\033[1m"
CLEAR_LINE="\033[2K"
LINE_UP="\033[1A"
RED="\033[31m"
WHITE="\033[37m"
GRAY="\033[90m"
BLUE="\033[34m"
GREEN="\033[32m"
RESET="\033[0m"
rougefonce='\033[0;31m'
vertfonce='\033[0;32m'
vertclair='\033[1;32m'
orange='\033[0;33m'
blanc='\033[1;37m'
magenta='\033[0;35m'
neutre='\033[0;m'

export GIT_REPO="https://api.github.com/repos/fleizean/sleepwipe"
export BRANCH_NAME="main"
export COMMITS_NUM="1"

if ! command -v jq &> /dev/null; then
    printf " ${GREEN} jq not found installing...\n${RESET}"
    brew install jq  # jq paketini yüklemek için kullanılan komut
fi

if ! command -v curl &> /dev/null; then
    printf " ${GREEN} curl not found installing...\n${RESET}"
    brew install curl  # curl paketini yüklemek için kullanılan komut
fi

curl --silent --insecure --request GET --header "Accept: application/vnd.github.inertia-preview+json" "$GIT_REPO/commits?sha=$BRANCH_NAME&page=1&per_page=1000" | jq --raw-output '.[] | "\(.commit.author.date)"' | awk 'NF' | awk '{$1=$1;print}' | head -$COMMITS_NUM | awk '{print substr($1, 1, 10)}' > scripts/apiresult.txt
