package md.dani3lz.tmpslab1.AbstractFactory.Components;

import md.dani3lz.tmpslab1.AbstractFactory.AbstractComponents;
import md.dani3lz.tmpslab1.AbstractFactory.RAM;

import java.util.ArrayList;
import java.util.List;

public class HyperX implements RAM {
    public static List<AbstractComponents> hyperXs = new ArrayList<>();
    private String model;
    private double rank;
    private int price;
    private int memory;

    public HyperX(String model, double rank, int price, int memory, String type){
        this.model = model;
        this.rank = rank;
        this.price = price;
        this.memory = memory;
        hyperXs.add(this);
    }

    @Override
    public String model() {
        return model;
    }

    @Override
    public double ranking() {
        return rank;
    }

    @Override
    public int price() {
        return price;
    }

    @Override
    public int memory() {
        return memory;
    }
}
