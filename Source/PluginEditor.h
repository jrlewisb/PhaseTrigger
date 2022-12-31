/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "CustomLNF.h"
#include "EnvelopeView.h"
#include "PhaserView.h"
#include "LEDLight.h"

//shared component defs below here
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

class SwitchViewComponent : public juce::Component
{
    
    void paint(juce::Graphics& g) override{
        
    }
    
    void setCurrentView(juce::Component* newView){
        
    }
    
    void resized() override{
        auto bounds = getLocalBounds();
    }
    
    private:
    juce::Component* currentView;
    
    
};



class OutputSettingsComponent : public juce::Component
{
    
};

//Finally define the processoreditor


class PhaseTriggerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    PhaseTriggerAudioProcessorEditor (PhaseTriggerAudioProcessor&);
    ~PhaseTriggerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PhaseTriggerAudioProcessor& audioProcessor;
    
    //Component instances
    TriggerComponent triggerComponent;
    EnvelopeView envelopeView;
    PhaserView phaserView;
    SwitchViewComponent switchViewComponent;
    OutputSettingsComponent outputSettingsComponent;
    
    //Bounds
    juce::Rectangle<int> triggerBounds;
    juce::Rectangle<int> currentViewBounds;
    juce::Rectangle<int> switchViewButtonBounds;
    juce::Rectangle<int> outputSettingsBounds;
    
    //Stateful variables
    juce::Component* currentView;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PhaseTriggerAudioProcessorEditor)
};

