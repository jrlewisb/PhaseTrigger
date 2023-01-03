/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "./PluginProcessor.h"
#include "./CustomLNF.h"
//Include Views
#include "./Views/EnvelopeView.h"
#include "./Views/PhaserView.h"
//Include Core (Some arrangement of many, laid out) Components
#include "./CoreComponents/TriggerComponent.h"
#include "./CoreComponents/TopMenuBar.h"
//Include (Re-usable, utility) Components
#include "./Components/LEDLight.h"
#include "./Components/MenuButtonComponent.h"


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
    //Main Components with children & complex interactions
    TriggerComponent triggerComponent;
    EnvelopeView envelopeView;
    PhaserView phaserView;
    TopMenuBar topMenuBar;

    //Simple Components
    

    //OutputSettingsComponent outputSettingsComponent;
    
    //Stateful variables
    juce::Component* currentView;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PhaseTriggerAudioProcessorEditor)
};

