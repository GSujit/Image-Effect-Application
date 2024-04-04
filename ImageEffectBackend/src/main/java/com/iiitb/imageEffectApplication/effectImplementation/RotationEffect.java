package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueDiscreteEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.Pixel;

import static libraryInterfaces.RotationInterface.applyRotation;

public class RotationEffect implements SingleValueDiscreteEffect {

    private int value;

    public void setParameterValue(int parameterValue) throws IllegalParameterException{

        if(parameterValue > 3 || parameterValue < 0){
            throw new IllegalParameterException("Parameter must be in the range 0 - 3");
        }
        else {
            this.value = parameterValue;
        }
    }

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){

        if(this.value == 0) {
            loggingService.addLog(fileName, "Rotation", String.valueOf(0));
        } else if (this.value == 1) {
            loggingService.addLog(fileName, "Rotation", String.valueOf(90));
        } else if (this.value == 2) {
            loggingService.addLog(fileName, "Rotation", String.valueOf(180));
        }
        else if(this.value == 3){
            loggingService.addLog(fileName, "Rotation", String.valueOf(270));
        }

        image = applyRotation(image,this.value);

        return image;
    }


}
