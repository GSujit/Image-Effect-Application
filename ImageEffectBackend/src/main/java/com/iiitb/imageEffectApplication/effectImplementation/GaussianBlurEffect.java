package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.Pixel;

import static libraryInterfaces.GaussianBlurInterface.applyGaussianBlur;

public class GaussianBlurEffect implements SingleValueParameterizableEffect {
    private float amount;

    public void setParameterValue(float parameterValue) throws IllegalParameterException {

        if(parameterValue > 50 || parameterValue < 0){
            throw new IllegalParameterException("Radius must be in the range 0 - 50");
        }
        else {
            this.amount = parameterValue;
        }

    }

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){

        loggingService.addLog(fileName,"Gaussian Blur",String.valueOf(this.amount));

        image = applyGaussianBlur(image,amount);

        return image;
    }
}
