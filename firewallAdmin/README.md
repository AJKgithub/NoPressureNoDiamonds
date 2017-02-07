# Firewall Notes

### PaloAlto
[CLI](https://www.paloaltonetworks.com/documentation/61/pan-os/pan-os/device-management/use-the-command-line-interface-cli)
[Running on AWS](https://www.paloaltonetworks.com/products/secure-the-network/virtualized-next-generation-firewall/vm-series-for-aws)

### Linux
Add delay to packets on INTERFACE: [Source](https://superuser.com/questions/173751/how-to-deliberately-introduce-a-delay-for-incoming-udp-packets) [Source 2](http://bencane.com/2012/07/16/tc-adding-simulated-network-latency-to-your-linux-server/) [tc Man Page](http://www.lartc.org/manpages/tc.txt)
`tc qdisc add dev $INTERFACE root netem delay 250ms`

[fail2ban](https://github.com/fail2ban/fail2ban)
