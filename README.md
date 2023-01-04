<h1> PhaseTrigger </h1>

<h4>PhaseTrigger is <sub>  eventually going to be  </sub> a simple audio plugin designed to help sound designers employ fine-tuned phasing effects. </h4>

This will be achieved via:
* Midi/Gate Triggered Envelopes
* Linked, or Independent centers and envelopes for individual phaser notches
* 1 - 12 Notches available to control.

Created using JUCE Framework, this is currently a non-profit educational project for my own learning and enjoyment.

<h3> Progress </h3>
<h4> 4 Jan - 5 Jan </h4>

![Progress v2](./Images/Progress2.png)

Thanks to some help from [Matthjis Hollemans](https://leanpub.com/u/machinethink) I was able to get the visualisation for the logspaced frequency spectrum onto the plugin!

I also made some custom components, the MouseLockSlider (& its MouseLockSliderWrapper for when we want to add a label to the control). This component is intended to mirror ableton live's value adjustment, where upon clicking your mouse is captured and you can drag up and down to adjust the value.

Using these components, I made the "Notches" control, which indicates how many allpass notches should be present in the phaser. I also linked this control to its corresponding AudioProcessorParameter to ensure that the visualisation and the processor reflect the same values.

Visually, everything is working how I wanted it to. The next step will be a similar process of declaring another MouseLockSlider + Wrapper to handle the "Center" parameter. I also need to create the corresponding AudioProcessorParameter, and finally replace the "Magic Number" I am currently calculating the phaser notches around (10khz).


<h4> 30 Dec - 4 Jan </h4>
So far I have focused mainly on the GUI, and established a solid base to continue building the project upon. Components are generally quite independent allowing me to intuitively navigate to parts of my application.

After a bit of cowboy coding, I decided it would be helpful to mock-up a rough idea for the application layout. This included breaking the editor into main areas and dedicating components to handle multiple children in that area. Further down the line, this allowed me to keep my editor class nice and simple, only handling application level state changes and layout.
![Design v1](./Images/Design1.png)

By referencing the design (which I was not too emotionally attached to, but I needed a guide) I was able to develop a scaffold in which I am confident I can easily deliver the bulk of the application functionality from.
![Progress v1](./Images/Progress1.png)

Next steps are to put together the phaser view and the envelope view. I haven't touched the processor side of the application yet, but ultimately these views will be filled with sliders & attachments that interact with the audioprocessorvaluetree.

Milestones achieved
- Views can be switched by clicking the envelope or phaser menuButtons
- Settings has a popup menu attached to it with a working callback for future extensions (new, load, save etc)
- Custom look and feel is doing something


