# Simrigs for Truck Sim
Simrigs for Euro Truck and American Truck simulator (referred to generically as "Truck Sim") are significanly less complex than for train simulators, in no small part thanks to the commercial availability of simrigs for such a purpose (and adjacent purposes like racing). Crucially, the main control systems of a wheel, pedals, and shifters are already commercially available, and thus "simrig" in this context generally refers to the physical frame and connected peripherals rather than requiring an entire control panel to be designed from scratch.

This makes a simrig for Truck Sim a significantly easier project to take through to completion, as rather than designing control systems, generally only a button panel is required. The physical frame of the simrig can also take some consideration, should a commercial variant not be on the cards.

## Physical Frame

Numerous extruded aluminum frames are available, from various manufacturers. Alternatively, a wooden frame can be made, as described by [SimAddict](https://www.simaddict.net/sim-racing-guides/how-to-build-a-sim-rig-with-wood). Seat considerations include buying a pickup truck seat from a local junkyard, according to [Reddit](https://www.reddit.com/r/trucksim/comments/yqmvq3/looking_for_seat_tips_for_my_sim_rig_so_i_can/), or buying forklift seats on Amazon, like [Linus Tech Tips' video](https://www.youtube.com/watch?v=cgfx2mLSI-A).

## Button Panel

Button panel can be made to various levels of realism. TODO: Add screenshots of trucks to be used. Keyed ignition may require some additional logic, though since we are using an Arduino we may be able to bypass the editing of `controls.sii` that [George on the SCS forums](https://forum.scssoft.com/viewtopic.php?t=311011) suggests. The main reason for starting with a truck Simrig is also here: I can easily mock up a button panel on a breadboard using one of the many Arduino kits available on AliExpress.

## Additional
