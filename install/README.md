# Installation Guide

Edit config.xml file
```xml
<?xml version="1.0" encoding="utf-8"?>
<Config>
    <Host
        interface="interface"
        ip="192.168.1.10"
        netmask="24"
    />

    <Appliance
        ip="192.168.1.10"
        netmask="24"
    >
        <DHCP
            start="192.168.1.100"
            end="192.168.1.200"
        />
    </Appliance>

    <Images 
        boot="path/to/image_init_ram"
        sysupgrade="path/to/image_sysupgrade"
    />
</Config>
```