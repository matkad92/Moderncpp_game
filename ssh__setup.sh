#!/bin/bash

# Start the SSH agent
eval $(ssh-agent -s)

# Add your SSH key to the agent
ssh-add E:/C++/QT/gitHub_rsa

# Print a message indicating that the key has been added
echo "SSH key added to the agent"