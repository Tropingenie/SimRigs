# Simrigs for Truck Sim
Simrigs for Euro Truck and American Truck simulator (referred to generically as "Truck Sim") are significanly less complex than for train simulators, in no small part thanks to the commercial availability of simrigs for such a purpose (and adjacent purposes like racing). Crucially, the main control systems of a wheel, pedals, and shifters are already commercially available, and thus "simrig" in this context generally refers to the physical frame and connected peripherals rather than requiring an entire control panel to be designed from scratch.

This makes a simrig for Truck Sim a significantly easier project to take through to completion, as rather than designing control systems, generally only a button panel is required. The physical frame of the simrig can also take some consideration, should a commercial variant not be on the cards.

## The Basics

A basic simrig for trucking (or racing or bussing) typically consists of a few basic parts:
1. Wheel (and pedals and shifter)
1. Physical Frame
1. Button panel(s)
1. Sim Dashboard (optional)

For an initial design, I am bringing my existing Thrustmaster T300 wheel, so all that is needed is a frame and button panel. Sim dashboard is a nice addon, but not strictly necessary (as it only repeats information available in-game), requires an Android tablet, and appears to be Windows only for integration with Truck Sim.

### Physical Frame

Numerous extruded aluminum frames are available, from various manufacturers. Alternatively, a wooden frame can be made, as described by [SimAddict](https://www.simaddict.net/sim-racing-guides/how-to-build-a-sim-rig-with-wood). Seat considerations include buying a pickup truck seat from a local junkyard, according to [Reddit](https://www.reddit.com/r/trucksim/comments/yqmvq3/looking_for_seat_tips_for_my_sim_rig_so_i_can/), or buying forklift seats on Amazon, like [Linus Tech Tips' video](https://www.youtube.com/watch?v=cgfx2mLSI-A).

### Button Panel

Button panel can be made to various levels of realism. TODO: Add screenshots of trucks to be used. Keyed ignition may require some additional logic, though since we are using an Arduino we may be able to bypass the editing of `controls.sii` that [George on the SCS forums](https://forum.scssoft.com/viewtopic.php?t=311011) suggests. The main reason for starting with a truck Simrig is also here: I can easily mock up a button panel on a breadboard using one of the many Arduino kits available on AliExpress.

### Additional Resources

Technically this is going to be more of a look into various "sim dashboards" since I ended up exploring that. 

Sim dashboards are, practically speaking, what they say on the tin. A virtual diplay of a dashboard--speedometors, tachometers, etc. but often also providing support for virtual button panels. My use case is primarily the various gauges though, since I can find those difficult to see in game on certain trucks.

In my search I've found three implementations of a sim dashboard:

There is of course stryder-it's [Sim Dashboard](https://www.stryder-it.de/simdashboard/ets2_ats) which as mentioned requires running a Windows-based server (DLL injector?) on the same machine as the game to transmit data to an Android tablet. This potentially could be used on Linux as well, since in theory it is possible to install the Sim Dashboard server to the correct WINE environment, but frankly not worth the effort. Sim Dashboard is completely free, as far as I can tell.

Next is Pyrofrog Studio's [Dashpanel](https://www.pyrofrogstudios.com/dashpanel.html). It, too, requires a server to be run locally, which is available on Steam. On paper, it is the same as Sim Dashboard, but with one key difference: Dashpanel requires purchases of DLC on Steam to unlock its full functionality; for Truck Simulator this is a CA$4.99 purchase. I am not sure why anyone would buy this over Sim Dashboard to be honest.

The final product I have found is [SimHub](https://www.simhubdash.com/). Simhub expands on the offerings by not only providing the expected virtual dashboard and button panels, but various feedback and motion systems as well. Critically, if shakers are desired, Simhub will be all but required, as it is the only one of these that supports a motion system, thus reducing the number of "overhead software" running. Like the previous two offerings, the server software appears to be Windows only. SimHub has a free offering, but fullly-featured requires a "choose your price" license costing at minimum €6.99.

## The Specifics

I will be basing the available controls on [this Steam guide by lapidary.master](https://steamcommunity.com/sharedfiles/filedetails/?id=2378657608), though obviously updating it to the 2024 control scheme by verifying manually in-game.
