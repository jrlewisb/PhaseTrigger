#include "./PluginProcessor.h"
#include "./PluginEditor.h"

//==============================================================================
PhaseTriggerAudioProcessorEditor::PhaseTriggerAudioProcessorEditor (PhaseTriggerAudioProcessor& p)
    //Initialiser List
    : AudioProcessorEditor (&p),
      audioProcessor (p),
      phaserView(p.apvts),
      settingsPopupMenu()
      
{
    //Set LNF and Size so they can be referenced throughout the project
    juce::LookAndFeel::setDefaultLookAndFeel(&customLNF);
    setSize (500, 250);
    
    //Initialisation of Current View and related visual context
    currentView = &phaserView;
    topMenuBar.getPhaserButton().setButtonColour(MyColours::SELECTED_VIEW);
    topMenuBar.getPhaserButton().setTextColour(MyColours::SELECTED_VIEW_TEXT);
    
    //Add Items to the Settings popup menu
    settingsPopupMenu.addItem(juce::PopupMenu::Item("New").setID(1));
    settingsPopupMenu.addItem(juce::PopupMenu::Item("Open").setID(2));
    settingsPopupMenu.addItem(juce::PopupMenu::Item("Save").setID(3));

    //Assign self as listener to Top menu buttons
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
    //Destructor, should remove self as listener from all previously registered in constructor
    topMenuBar.getPhaserButton().removeListener(this);
    topMenuBar.getEnvelopeButton().removeListener(this);
    topMenuBar.getSettingsButton().removeListener(this);

}

void PhaseTriggerAudioProcessorEditor::settingsSelectionHandler(int result)
{
    DBG(result);
    //TODO: Callback for the Top Menu Settings dropdown, include desired functionality based on the result of this callback
    switch (result)
    {
    case 1:
        //"NEW" => Initialise blank editor with default settings
        break;
    case 2:
        //"OPEN" => Open file and restore audioprocessorvaluetreestate from serialised data
        break;
    case 3:
        //"SAVE" => Save audioprocessorvaluetreestate to serialised data and allow user to choose location
        break;
    default:
        break;
    }
}

void PhaseTriggerAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    if (button == &topMenuBar.getPhaserButton()) //PhaserView clicked
    {
        topMenuBar.getPhaserButton().setButtonColour(MyColours::SELECTED_VIEW);
        topMenuBar.getPhaserButton().setTextColour(MyColours::SELECTED_VIEW_TEXT);
        topMenuBar.getEnvelopeButton().setButtonColour(MyColours::VIEW);
        topMenuBar.getEnvelopeButton().setTextColour(MyColours::VIEW_TEXT);
        currentView->setVisible(false);
        currentView = &phaserView;
        addAndMakeVisible(currentView);
    }
    else if (button == &topMenuBar.getEnvelopeButton()) //EnvelopeView clicked
    {
        topMenuBar.getPhaserButton().setButtonColour(MyColours::VIEW);
        topMenuBar.getPhaserButton().setTextColour(MyColours::VIEW_TEXT);
        topMenuBar.getEnvelopeButton().setButtonColour(MyColours::SELECTED_VIEW);
        topMenuBar.getEnvelopeButton().setTextColour(MyColours::SELECTED_VIEW_TEXT);
        currentView->setVisible(false);
        currentView = &envelopeView;
        addAndMakeVisible(currentView);
    }else if( button == &topMenuBar.getSettingsButton()) //Settings button clicked
    {
        settingsPopupMenu.showMenuAsync(juce::PopupMenu::Options().withTargetComponent(&topMenuBar.getSettingsButton()),
            [&](int result){settingsSelectionHandler(result);});
    }
}


void PhaseTriggerAudioProcessorEditor::paint (juce::Graphics& g)
{
    /*
     Simple paint function as most painting is handled by components,
     this class should handle setting bounds of children,
     and callbacks that affect the top-level editor state.
    */
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void PhaseTriggerAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    
    auto topBounds = bounds.removeFromTop(bounds.getHeight() * 0.15);   //Top Menu Bar
    auto midBounds = bounds.removeFromTop(bounds.getHeight() * 0.7);    //Area for the Views
    auto bottomBounds = bounds;                                         //Bottom section for components
    
    //TOP
    topMenuBar.setBounds(topBounds);

    //MIDDLE
    phaserView.setBounds(midBounds);    //these will be set visible / invisible
    envelopeView.setBounds(midBounds);  //based on which of the buttons are pressed in the tab component
    
    //BOTTOM
    auto triggerBounds = bottomBounds.removeFromLeft(bottomBounds.getWidth() * 0.2);
    triggerComponent.setBounds(triggerBounds);
    outputSettingsComponent.setBounds(bottomBounds);




    
    
}
