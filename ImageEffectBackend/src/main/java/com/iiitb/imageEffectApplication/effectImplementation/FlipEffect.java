package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.DiscreteEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.Pixel;

import java.util.Objects;

import static libraryInterfaces.FlipInterface.applyFlip;

public class FlipEffect implements DiscreteEffect {
    private int horizontalFlipValue, verticalFlipValue;

    public void selectOptionValue(String optionName, int value) throws IllegalParameterException{

        if(optionName.equals("horizontal") || optionName.equals("vertical")){
            if(optionName.equals("horizontal")) {
                if (horizontalFlipValue == 1 || horizontalFlipValue == 0) {
                    this.horizontalFlipValue = value;
                }
                else {
                    throw new IllegalParameterException("Horizontal value must be 0 or 1");
                }
            }
            else if (verticalFlipValue == 1 || verticalFlipValue == 0) {
                this.verticalFlipValue = value;

            }
            else {
                throw new IllegalParameterException("Vertical value must be 0 or 1");
            }
        }
        else {
            throw new IllegalParameterException("Option must be horizontal or vertical");
        }

    }

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){

        if(this.horizontalFlipValue == 0 && this.verticalFlipValue == 0) {
            loggingService.addLog(fileName, "Flip", "No Flip");
        } else if (this.horizontalFlipValue == 0 && this.verticalFlipValue == 1) {
            loggingService.addLog(fileName, "Flip", "Vertical Flip");
        } else if (this.horizontalFlipValue == 1 && this.verticalFlipValue == 0) {
            loggingService.addLog(fileName, "Flip", "Horizontal Flip");
        }
        else if(this.horizontalFlipValue == 1 && this.verticalFlipValue == 1){
            loggingService.addLog(fileName, "Flip", "Horizontal and Vertical FLip");
        }
        
        image = applyFlip(image,this.horizontalFlipValue,this.verticalFlipValue);

        return image;
    }

}
