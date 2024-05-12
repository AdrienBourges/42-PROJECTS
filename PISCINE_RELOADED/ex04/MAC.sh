ifconfig | grep 'ether' | cut -c 8- | sed 's/ $//'
ifconfig | grep 'ether' | awk '{print $2}'

