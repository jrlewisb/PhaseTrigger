/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "./PluginProcessor.h"
#include "./PluginEditor.h"

//==============================================================================
PhaseTriggerAudioProcessorEditor::PhaseTriggerAudioProcessorEditor (PhaseTriggerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), settingsPopupMenu()
{
    juce::LookAndFeel::setDefaultLookAndFeel(&customLNF);
    setSize (500, 250);
    //init currentview
    currentView = &phaserView;
    topMenuBar.getPhaserButton().setButtonColour(MyColours::SELECTED_VIEW);
    topMenuBar.getPhaserButton().setTextColour(MyColours::SELECTED_VIEW_TEXT);
    
    //init settings popupmenu
    settingsPopupMenu.addItem(juce::PopupMenu::Item("New").setID(1));
    settingsPopupMenu.addItem(juce::PopupMenu::Item("Open").setID(2));
    settingsPopupMenu.addItem(juce::PopupMenu::Item("Save").setID(3));

    //assign listeners
    topMenuBar.getPhaserButton().addListener(this);
    topMenuBar.getEnvelopeButton().addListener(this);
    topMenuBar.getSettingsButton().addListener(this);
    
    //make components visible
    addAndMakeVisible(topMenuBar);
    addAndMakeVisible(&triggerComponent);
    addAndMakeVisible(currentView);
    addAndMakeVisible(outputSettingsComponent);

    
}

PhaseTriggerAudioProcessorEditor::~PhaseTriggerAudioProcessorEditor()
{
  topMenuBar.getPhaserButton().removeListener(this);
  topMenuBar.getEnvelopeButton().removeListener(this);
  topMenuBar.getSettingsButton().removeListener(this);

}

void PhaseTriggerAudioProcessorEditor::settingsSelectionHandler(int result)
{
    DBG(result);
    //todo
    switch (result)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
}

void PhaseTriggerAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    if (button == &topMenuBar.getPhaserButton())
    {
        topMenuBar.getPhaserButton().setButtonColour(MyColours::SELECTED_VIEW);
        topMenuBar.getPhaserButton().setTextColour(MyColours::SELECTED_VIEW_TEXT);
        topMenuBar.getEnvelopeButton().setButtonColour(MyColours::VIEW);
        topMenuBar.getEnvelopeButton().setTextColour(MyColours::VIEW_TEXT);
        currentView->setVisible(false);
        currentView = &phaserView;
        addAndMakeVisible(currentView);
    }
    else if (button == &topMenuBar.getEnvelopeButton())
    {
        topMenuBar.getPhaserButton().setButtonColour(MyColours::VIEW);
        topMenuBar.getPhaserButton().setTextColour(MyColours::VIEW_TEXT);
        topMenuBar.getEnvelopeButton().setButtonColour(MyColours::SELECTED_VIEW);
        topMenuBar.getEnvelopeButton().setTextColour(MyColours::SELECTED_VIEW_TEXT);
        currentView->setVisible(false);
        currentView = &envelopeView;
        addAndMakeVisible(currentView);
    }else if( button == &topMenuBar.getSettingsButton())
    {
        settingsPopupMenu.showMenuAsync(juce::PopupMenu::Options().withTargetComponent(&topMenuBar.getSettingsButton()),
            [&](int result){settingsSelectionHandler(result);});
    }
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
    auto topBounds = bounds.removeFromTop(bounds.getHeight() * 0.15);
    auto midBounds = bounds.removeFromTop(bounds.getHeight() * 0.7);
    auto bottomBounds = bounds;

    //top bar
    topMenuBar.setBounds(topBounds);

    //these will be set visible / invisible based on which of the buttons are pressed in the tab component
    phaserView.setBounds(midBounds);
    envelopeView.setBounds(midBounds);
    //currentView->setBounds(midBounds);
    //always visible
  
    //bottom layout
    auto triggerBounds = bottomBounds.removeFromLeft(bottomBounds.getWidth() * 0.2);
    triggerComponent.setBounds(triggerBounds);

    outputSettingsComponent.setBounds(bottomBounds);




    
    
}
