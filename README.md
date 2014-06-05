atp2EQ
======
This is the .dll and the source files for a Parametric 6 Band VST Equalizer. 
It was coded for a semester project in the course Audio Engineering and Production.
To Compile you'll need to get the VST SDK (3.x +) from the Steinberg developer site ( its free, just register)
and put the .cpp and .h files in the source folder ( propably have to change the relative Paths of the includes)
of any sample project. 
The EQ is IIR 2.Order with Peak, High/Lowpass, High/Lowshelf filters implemented.
For the formulas of the Biquad coefficients we used the ones from the EQ-Cookbook of Robert Bristow-Johnson
(http://www.musicdsp.org/files/Audio-EQ-Cookbook.txt)

Though it is not perfect, the project may give you some insights in VST programming and save you some time,
since the examples in the VST SDK are somehow hard to grasp for newbies.

All the best,

Dennis and Levin
