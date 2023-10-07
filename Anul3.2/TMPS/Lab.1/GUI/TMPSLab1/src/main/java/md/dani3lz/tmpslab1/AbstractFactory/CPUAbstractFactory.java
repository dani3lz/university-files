package md.dani3lz.tmpslab1.AbstractFactory;

import md.dani3lz.tmpslab1.AbstractFactory.Components.AMD;
import md.dani3lz.tmpslab1.AbstractFactory.Components.Intel;

public class CPUAbstractFactory implements AbstractFactory<CPU>{

    @Override
    public CPU createComponent(String corporation, String model, double rank, int price, int memory, String type) {
        if(corporation.equalsIgnoreCase("Intel")){
            return new Intel(model, rank, price, memory, type);
        } else if(corporation.equalsIgnoreCase("AMD")){
            return new AMD(model, rank, price, memory, type);
        }
        return null;
    }
}
