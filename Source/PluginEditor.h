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
#include "./CoreComponents/OutputSettingsComponent.h"



class PhaseTriggerAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Button::Listener
{
public:
    PhaseTriggerAudioProcessorEditor (PhaseTriggerAudioProcessor&);
    ~PhaseTriggerAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    //custom
    void settingsSelectionHandler(int result);

    //virtuals to override
    void buttonClicked(juce::Button* button) override;

private:
    CustomLNF customLNF;
    PhaseTriggerAudioProcessor& audioProcessor;
    
    //Component instances
    //Main Components with children & complex interactions
    TriggerComponent triggerComponent;
    EnvelopeView envelopeView;
    PhaserView phaserView;
    TopMenuBar topMenuBar;
    OutputSettingsComponent outputSettingsComponent;

    //Simple Components
    juce::PopupMenu settingsPopupMenu;
    

    //OutputSettingsComponent outputSettingsComponent;
    
    //Stateful variables
    juce::Component* currentView;

    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PhaseTriggerAudioProcessorEditor)
};

