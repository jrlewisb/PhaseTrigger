#pragma once
#include <JuceHeader.h>
#include "../Components/LEDLight.h"

struct TriggerComponent : juce::Component
/*
    This component describes the layout of the "Trigger" label,
    the LEDLight component that will flick red/green depending on wether the trigger condition is met,
    and the On/Off button that will allow us to switch between trigger and LFO mode for modulation.
*/
{
public:
    TriggerComponent() : onOffButton("On / Off"),           //onOffButton is a textbutton
                         textLabel("Trigger","Trigger"),    //textLabel is a label, to be honest it could just be text
                         ledLight()                         //ledLight is a custom component of type LEDLight
    {
        textLabel.setJustificationType(juce::Justification(12));
        textLabel.setColour(juce::Label::textColourId, MyColours::VIEW_TEXT);
        addAndMakeVisible(textLabel);
        addAndMakeVisible(ledLight);
        addAndMakeVisible(onOffButton);
    }
    
    void paint(juce::Graphics& g) override{
        g.setColour(MyColours::VIEW);
        g.fillRect(getLocalBounds());
    }

    void resized() override{
        auto bounds = getLocalBounds();
        
        int marginY = bounds.getHeight() * 0.05f;
        bounds.removeFromTop(marginY); bounds.removeFromBottom(marginY);
        int marginX = bounds.getWidth() * 0.1f;
        bounds.removeFromLeft(marginX); bounds.removeFromRight(marginX);
        
        auto labelBounds = bounds.removeFromTop(bounds.getHeight() * 0.3);
        auto ledLightBounds = bounds.removeFromTop(bounds.getHeight() * 0.3);
        
        textLabel.setBounds(labelBounds);
        ledLight.setBounds(ledLightBounds);
        onOffButton.setBounds(bounds);
    }
    
private:
    juce::TextButton onOffButton;
    juce::Label textLabel;
    LEDLight ledLight;
};
