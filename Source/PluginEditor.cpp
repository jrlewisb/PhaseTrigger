/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PhaseTriggerAudioProcessorEditor::PhaseTriggerAudioProcessorEditor (PhaseTriggerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (600, 300);
    currentView = &phaserView;
    addAndMakeVisible(&triggerComponent);
    addAndMakeVisible(currentView);
    addAndMakeVisible(switchViewComponent);
    addAndMakeVisible(outputSettingsComponent);
    
}

PhaseTriggerAudioProcessorEditor::~PhaseTriggerAudioProcessorEditor()
{
}

//==============================================================================
void PhaseTriggerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    


}

void PhaseTriggerAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    auto totalWidth = bounds.getWidth();
    triggerBounds = bounds.removeFromLeft(totalWidth * 0.05f);
    switchViewBounds = bounds.removeFromLeft(totalWidth * 0.75f);
    outputSettingsBounds = bounds;
    
    triggerComponent.setBounds(triggerBounds);
    switchViewComponent.setBounds(switchViewBounds);
    outputSettingsComponent.setBounds(outputSettingsBounds);
    
    
}