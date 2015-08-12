//
//  ViewController.swift
//  First App
//
//  Created by Ali Sadreddini on 11/08/2015.
//  Copyright (c) 2015 Ali Sadreddini. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    var index = 0
    @IBOutlet weak var messageLabel: UILabel!
    
    let messageArray = ["Test 1", "Test 2", "Test 3", "Dates look like mummified Testicles!!"]
//    let messageArray = ["Test 1", "Test 2", "Test 3", "Dates look like mummified Testicles!!", 10]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


    @IBAction func doButtonTap(sender: AnyObject) {
        let nextString = self.messageArray[index]
        self.messageLabel.text = nextString

//        if let nextString = self.messageArray[index] as? String {
//            self.messageLabel.text = nextString
//        }
        
        index++
        index %= self.messageArray.count
    }
}

