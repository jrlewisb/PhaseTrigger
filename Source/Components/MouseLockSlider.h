
#pragma once
#include <JuceHeader.h>

struct MouseLockSlider : public juce::Slider
/*todo: refactor this class alongside the wrapper and make the layouts into a flexbox so it fills its space like
 ^ font height (ie; 16px)
 ^ control font height (ie; 14px)
 | empty space (bounds - (font height + control font height)
 */
{
    MouseLockSlider()
    {
    }
    void paint(juce::Graphics& g) override {
        g.setColour(MyColours::SELECTED_VIEW_DETAIL);
        g.fillRoundedRectangle(getX(), getY(), getWidth(), getHeight(), 2.f);
        g.setColour(MyColours::SELECTED_VIEW_TEXT);
        g.setFont(MyFonts::FONT_MED);
        
        
        g.drawText(getTextFromValue(getValue()), 3, 0, getWidth(), getHeight(), juce::Justification(9));
        
        
    }
    void resized() override {
    }

    void mouseDown(const juce::MouseEvent& event) override
    {
        capturedMousePosition = event.source.getScreenPosition();
        lastReadMouseY = event.position.y;
        event.source.enableUnboundedMouseMovement(true, false);
    }

    void mouseDrag(const juce::MouseEvent& event) override
    {
        float delta = event.position.y - lastReadMouseY;
        if(std::abs(delta) >= sensitivity){
            setValue(getValue() - (delta/sensitivity));
            lastReadMouseY = event.position.y;
        }
        
        
    }

    void mouseUp(const juce::MouseEvent& event) override
    {
        event.source.enableUnboundedMouseMovement(false, false);
        DBG(typeid(event.source).name());
        //event.source.setScreenPosition(capturedMousePosition); //requires fix later, for now it works without

    }

    void setSensitivity(int sensitivityToSet){
        //sensitivity is the amount of pixels +- the mouse has to travel before updating the value on the slider
        sensitivity = sensitivityToSet;
    }
    
    private:
    juce::Point<float> capturedMousePosition;
    float lastReadMouseY;
    int sensitivity = 20;


};
