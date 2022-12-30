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
                                textLabel("Trigger")
    {
        
        addAndMakeVisible(textLabel);
        addAndMakeVisible(ledLight);
        addAndMakeVisible(onOffButton);
    }
    
    void paint(juce::Graphics& g) override{
        g.drawText("I am the Trigger",0,0,100,100, juce::Justification(1));
    }

    void resized() override{
        auto bounds = getLocalBounds();
        juce::FlexBox flexbox(juce::FlexBox::Direction::column, juce::FlexBox::Wrap::noWrap, juce::FlexBox::AlignContent::spaceBetween, juce::FlexBox::AlignItems::center, juce::FlexBox::JustifyContent::spaceBetween);
        
        
        flexbox.items.add(textLabel);
        flexbox.items.add(ledLight);
        flexbox.items.add(onOffButton);
        flexbox.performLayout(bounds);
    }
    
private:
    juce::TextButton onOffButton;
    juce::Label textLabel;
    LEDLight ledLight;
};

class SwitchViewComponent : public juce::Component
{
    
    void paint(juce::Graphics& g) override{
        g.drawText("Switch", getX(), getY(), getWidth(), getHeight(), juce::Justification(8));
    }
    void resized() override{
        auto bounds = getLocalBounds();
    }
    
    
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
    juce::Rectangle<int> viewBounds;
    juce::Rectangle<int> switchViewBounds;
    juce::Rectangle<int> outputSettingsBounds;
    
    //Stateful variables
    juce::Component* currentView;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PhaseTriggerAudioProcessorEditor)
};

