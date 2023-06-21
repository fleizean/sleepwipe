git clone https://github.com/fleizean/sleepwipe.git ~/.sleepwipe || git -C ~/.sleepwipe pull && make -C ~/.sleepwipe
mkdir -p ~/.local/bin/ && cp ~/.sleepwipe/sleepwipe ~/.local/bin/
if ls "$HOME"/.local/bin/sleepwipe &>/dev/null; then
  sleep 0.5
  echo -e "\n\033[32m -- sleepwipe has been successfully set! --\n\033[0m"
else
    echo a
fi

shell_f=`echo -n "$SHELL" | awk -F / '{print $3}'`
shell_f="${HOME}/.${shell_f}rc"

if ! grep "\<export PATH=\$PATH:~/.local/bin\>" <"$shell_f" &>/dev/null; then
  echo "\nexport PATH=\$PATH:~/.local/bin/" >> "$shell_f"
fi
source ~/.zshrc
sleepwipe -h
#murmurlab
