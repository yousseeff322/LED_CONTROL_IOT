function controlLED(status) {
    document.getElementById('led-status').textContent = `LED is turned ${status}`;
    fetch('control_led.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: `status=${status}`
    });
}

