#pragma once
#include <JuceHeader.h>
#include "../Components/LEDLight.h"

class TriggerComponent : public juce::Component
{
public:
    TriggerComponent() : onOffButton("On / Off"),
                         textLabel("Trigger","Trigger"),
                         ledLight()
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
