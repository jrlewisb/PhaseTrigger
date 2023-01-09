#pragma once
#include <JuceHeader.h>

class MenuButtonComponent : public juce::TextButton
{
public:
    MenuButtonComponent(juce::String text) 
    {
        setButtonText(text);

    }
    
    void paintButton(juce::Graphics& g, bool isMouseOverButton, bool isButtonDown) override
    {
        g.setColour(buttonColour);
        g.fillRect(getLocalBounds());
        g.setColour(textColour);
        g.setFont(20.0f);
        g.drawText(getButtonText(), getLocalBounds(), juce::Justification(36));
    }

//    void setButtonFunction(void(*funcToSet)(const juce::MouseEvent& event, MenuButtonComponent* mbc)){
//        this->buttonFunction = funcToSet;
//    }

    void setButtonColour(juce::Colour colourToSet){
        this->buttonColour = colourToSet;
        repaint();
    }
    
    void setTextColour(juce::Colour colourToSet){
        this->textColour = colourToSet;
        repaint();
    }
    
//    void mouseDown(const juce::MouseEvent& event) override
//    {
//        buttonFunction(event, this);
//    }

    private:
    //void(*buttonFunction)(const juce::MouseEvent& event, MenuButtonComponent& mbc);
    juce::Colour buttonColour = MyColours::VIEW;
    juce::Colour textColour = MyColours::VIEW_TEXT;
    
};
