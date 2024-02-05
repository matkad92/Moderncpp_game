#!/bin/bash

# Check if the SSH agent is already running
# if [ -z "$SSH_AGENT_PID" ] || ! ps -p $SSH_AGENT_PID > /dev/null; then
    # Start a new SSH agent
    eval $(ssh-agent -s)
#     export SSH_AGENT_PID
#     export SSH_AUTH_SOCK
# fi

# Add your SSH key to the agent
ssh-add E:/C++/QT/gitHub_rsa

# Print a message indicating that the key has been added
echo "SSH key added to the agent"
