#pragma once
#include <JuceHeader.h>

class TriggerComponent : public juce::Component
{
public:
    TriggerComponent() : onOffButton("On / Off"),
                         textLabel("Trigger","Trigger"),
                         ledLight()
    {
        textLabel.setJustificationType(juce::Justification(12));
        addAndMakeVisible(textLabel);
        addAndMakeVisible(ledLight);
        addAndMakeVisible(onOffButton);
    }
    
    void paint(juce::Graphics& g) override{
        g.setColour(juce::Colours::grey);
        g.fillRect(getLocalBounds());
    }

    void resized() override{
        auto bounds = getLocalBounds();
        auto labelBounds = bounds.removeFromTop(bounds.getHeight() * 0.2);
        auto ledLightBounds = bounds.removeFromTop(bounds.getHeight() * 0.5);
        
        textLabel.setBounds(labelBounds);
        ledLight.setBounds(ledLightBounds);
        
        int buttonMarginY = bounds.getHeight() * 0.3;
        bounds.removeFromTop(buttonMarginY); bounds.removeFromBottom(buttonMarginY);
        onOffButton.setBounds(bounds);
        
        
    }
    
private:
    juce::TextButton onOffButton;
    juce::Label textLabel;
    LEDLight ledLight;
};