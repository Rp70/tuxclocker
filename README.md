TuxClocker - A GUI overclocking utility for GNU/Linux
========================================
TuxClocker is a Qt5 overclocking tool. Currently supported cards are nvidia 600-series cards and newer. Support for AMD GPUs is planned.

# Screenshots
![main](https://i.imgur.com/fn8MoNj.png)

# Current features
- GPU monitoring (list and graph)
- Overclocking
- Overvolting
- Change power limit
- Fan mode selection
- Custom fan curve
- Profiles

# Planned features
- Multi-GPU support
- AMD support
- Rewrite nvidia controlling using libxnvctrl

# Requirements

- nvidia-smi
- nvidia-settings
- Qt libraries
- Coolbits set to the value you want (31 for all functionality)

# Installation

### Compilation
```
git clone https://github.com/Lurkki14/tuxclocker
cd tuxclocker
qmake rojekti.pro
make
make install (installs into /opt/tuxclocker/bin)
```

