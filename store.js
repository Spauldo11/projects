const store = {
    sweatpants: {
        inventory: 481,
        cost: 20
    },
    hoodies: {
        inventory: 39,
        cost: 35
    },
    shirt: {
        inventory: 159,
        cost: 15
    },
    socks: {
        inventory: 712,
        cost: 9
    }
};
const order = {
    items: [['sweatpants'], ['hoodies'], ['shirt'], ['socks']],
    giftcardBalance: 150
};
const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
const howMany = (order) => {
     return new Promise((resolve) => {
         readline.question('How many pairs of sweatpants would you like? ', numOfPants => {
             order.items[0].push(parseInt(numOfPants));
             store.sweatpants.inventory -= numOfPants;

             readline.question('How many hoodies would you like? ', numOfHoodies => {
                 order.items[1].push(parseInt(numOfHoodies));
                 store.hoodies.inventory -= numOfHoodies;

                 readline.question('How many shirts would you like? ', numOfShirt => {
                     order.items[2].push(parseInt(numOfShirt));
                     store.shirt.inventory -= numOfShirt;

                     readline.question('How many pairs of socks would you like? ', numOfSocks => {
                         order.items[3].push(parseInt(numOfSocks));
                         store.socks.inventory -= numOfSocks;

                         resolve(order);
                     })
                 })
             })
         })
     })
 };
const isInStock = (order) => {
    return new Promise((resolve) => {
        const items = order.items;
        let inStock = items.every(item => item[1] <= store[item[0]].inventory);
        if (inStock) {
            console.log('Everything is in stock, processing order now.')
            resolve(order)
        } else {
            throw new Error('Something in your order isn\'t in stock');
        }
    })
};
const canAfford = () => {
    setTimeout(() => {
        let giftcardBalance = order.giftcardBalance;
        const items = order.items;
        return new Promise((resolve) => {
            let total = 0;
            items.forEach(item => total += item[1] * store[item[0]].cost);
            let canAfford = giftcardBalance >= total;
            let newCardBalance = giftcardBalance -= total;
            if (canAfford) {
                readline.question(`That will be $${total}. Would you like to continue? (Y/N)`, yesOrNo => {
                    if (yesOrNo === 'Y' || yesOrNo === 'y') {
                        console.log(`Purchase successful, your new balance is $${newCardBalance}`)
                        shipItem();
                    } else {
                        console.log('Sorry, we wish to see you again!');
                        readline.close();
                    }
                })
            } else {
                throw new Error('Gift card balance too low. Please update your order');
            }
        })
    }, 1000)
};
const shipItem = () => {
    setTimeout(() => {
        const trackingNum = generateTrackingNum()
        console.log(`Your order has been shipped, it\'s tracking number is ${trackingNum}`)
        readline.close();
    }, 2000);
};
function generateTrackingNum() {
    return Math.floor(Math.random() * 99999)
};
howMany(order)
    .then((resolvedValue) => {
        isInStock(resolvedValue)
    }).then((resolvedValue) => {
        canAfford(resolvedValue);
    }).catch((error) => {
        console.error(error);
    }); 