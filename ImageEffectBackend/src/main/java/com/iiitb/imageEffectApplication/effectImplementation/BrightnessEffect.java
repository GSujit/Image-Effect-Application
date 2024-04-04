package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.Pixel;

import static libraryInterfaces.BrightnessInterface.applyBrightness;

public class BrightnessEffect implements SingleValueParameterizableEffect {

    private float amount;

    public void setParameterValue(float parameterValue) throws IllegalParameterException{

        if(parameterValue > 200 || parameterValue < 0){
            throw new IllegalParameterException("Parameter must be in the range 0 - 200");
        }
        else {
            this.amount = parameterValue;
        }

    }

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){

        loggingService.addLog(fileName,"Brightness",String.valueOf(this.amount));

        image = applyBrightness(image,amount);

        return image;
    }

}
