(function($) {
	Drupal.behaviors.viewsUIToUXAccordion = {
		attach: function(context, settings) {
			$(".views_uitoux_accordion ul.views-uitoux-accordion").zozoAccordion({
                theme: settings.views_uitoux_accordion.accordion_theme,
                orientation: "horizontal",
                active: 1,
                contentHeight: parseFloat(settings.views_uitoux_accordion.content_height),
                headerSize: parseFloat(settings.views_uitoux_accordion.header_size),
                headerFontSize: parseFloat(settings.views_uitoux_accordion.header_font_size),
                responsive: settings.views_uitoux_accordion.responsive == "1",
                minWindowWidth: parseFloat(settings.views_uitoux_accordion.min_window_width),
                scrollable: settings.views_uitoux_accordion.scrollable == "1",
                animation: {
                    easing: settings.views_uitoux_accordion.animation_easing,
                    duration: parseInt(settings.views_uitoux_accordion.animation_duration)
                }
            });
		}
	};
})(jQuery);